//
// App.xaml.cpp
// Implementation of the App class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Group4_project;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

#include <ppltasks.h> 
using namespace concurrency;
using namespace Windows::Storage;
using namespace Windows::ApplicationModel;

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
/// <summary>
/// アプリケーションが通常通りユーザーによって起動されたときに呼び出されます。
/// 他のエントリポイント（特定のファイルを開くための起動など）が使用される場合もあります。
/// </summary>
/// <param name="e">起動リクエストおよびプロセスに関する詳細情報。</param>
void App::OnLaunched(LaunchActivatedEventArgs^ e)
{
	auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

	// ウィンドウにすでにコンテンツがある場合はアプリの初期化を繰り返さず、ウィンドウをアクティブにするだけ
	if (rootFrame == nullptr)
	{
		// ナビゲーションコンテキストとしてFrameを作成し、SuspensionManagerキーと関連付ける
		rootFrame = ref new Frame();

		rootFrame->NavigationFailed += ref new NavigationFailedEventHandler(this, &App::OnNavigationFailed);

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// TODO: 必要に応じて保存されたセッション状態を復元し、復元完了後に最終的な起動手順をスケジューリングする
		}

		if (e->PrelaunchActivated == false)
		{
			if (rootFrame->Content == nullptr)
			{
				// 最初のページにナビゲートする
				rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
			}

			// 現在のウィンドウにFrameを配置する
			Window::Current->Content = rootFrame;
		}
	}

	//✅ users.csvをDataフォルダーからLocalFolderにコピー（まだ存在しない場合のみ）
	auto localFolder = ApplicationData::Current->LocalFolder;
	create_task(localFolder->TryGetItemAsync("users.csv")).then([=](IStorageItem^ item) -> concurrency::task<void>
		{
			if (item == nullptr)
			{
				auto installFolder = Package::Current->InstalledLocation;
				return create_task(installFolder->GetFolderAsync("Data")).then([=](StorageFolder^ dataFolder) -> concurrency::task<void>
					{
						return create_task(dataFolder->GetFileAsync("users.csv")).then([=](StorageFile^ sourceFile) -> concurrency::task<void>
							{
								return create_task(sourceFile->CopyAsync(localFolder, "users.csv", NameCollisionOption::ReplaceExisting)).then([=](StorageFile^)
									{
										OutputDebugString((L"[Copy Done] users.csv saved to: " + localFolder->Path + L"\\users.csv\n")->Data());
										return concurrency::task_from_result();
									});
							});
					});
			}
			else
			{
				OutputDebugString((L"[Skip Copy] users.csv already exists in: " + localFolder->Path + L"\\users.csv\n")->Data());
				return concurrency::task_from_result();
			}
		}).then([](concurrency::task<void> previousTask)
			{
				try
				{
					previousTask.get();
				}
				catch (Exception^ ex)
				{
					OutputDebugString(L"[Error] Failed to copy or create users.csv file.\n");
				}
			});
		// ウィンドウをアクティブにする
		Window::Current->Activate();
}

/// <summary>
/// Invoked when application execution is being suspended.  Application state is saved
/// without knowing whether the application will be terminated or resumed with the contents
/// of memory still intact.
/// </summary>
/// <param name="sender">The source of the suspend request.</param>
/// <param name="e">Details about the suspend request.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void)sender;  // Unused parameter
	(void)e;       // Unused parameter

	// TODO: Save application state and stop any background activity
}

/// <summary>
/// Invoked when Navigation to a certain page fails
/// </summary>
/// <param name="sender">The Frame which failed navigation</param>
/// <param name="e">Details about the navigation failure</param>
void App::OnNavigationFailed(Platform::Object^ sender, NavigationFailedEventArgs^ e)
{
	throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}
