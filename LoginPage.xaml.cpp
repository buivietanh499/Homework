#include "pch.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"  
#include "HomePage.xaml.h"
#include "RegisterPage.xaml.h"
#include <Windows.UI.Xaml.Interop.h> 
#include <Data/UserDataHelper.h>

// 名前空間の使用宣言
using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;

// LoginPage クラスのコンストラクタ
LoginPage::LoginPage()
{
	InitializeComponent();
}

// ログインボタンがクリックされたときの処理
void LoginPage::LoginButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	std::wstring email = EmailTextBox->Text->Data(); // メールアドレスの取得
	std::wstring password = PasswordTextBox->Password->Data(); // パスワードの取得

	auto users = UserDataHelper::LoadUsers(); // ユーザーデータの読み込み

	// ユーザーリストをループして認証
	for (auto& user : users)
	{
		if (user.email == email && user.password == password)
		{
			this->Frame->Navigate(TypeName(HomePage::typeid)); // ホームページへ遷移
			return;
		}
	}

	// 認証失敗時のダイアログ表示
	ContentDialog^ dialog = ref new ContentDialog();
	dialog->Title = "ログインに失敗しました";
	dialog->Content = "メールアドレスまたはパスワードが間違っています。";
	dialog->CloseButtonText = "OK";
	dialog->ShowAsync();
}

// メインページに戻るボタンの処理
void LoginPage::GoBackToMainPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid)); // メインページへ遷移
}

// 新規登録ページへ遷移するボタンの処理
void LoginPage::GoToRegisterPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(RegisterPage::typeid)); // 登録ページへ遷移
}