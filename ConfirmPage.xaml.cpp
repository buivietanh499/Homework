//
// ConfirmPage.xaml.cpp
// ConfirmPage クラスの実装。
//

#include "pch.h"
#include "ConfirmPage.xaml.h"
#include "HomePage.g.h"
#include <collection.h>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <iostream>

using namespace Group4_project;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Platform;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel;
using namespace Windows::UI::Core;
using namespace concurrency;
using namespace std;


// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x411 を参照してください

Platform::String^ TrimString(Platform::String^ input)
{
	// Platform::String^ から std::wstring へ変換
	wstring ws(input->Data());
	// 左側 (ltrim)
	ws.erase(ws.begin(),
		find_if(ws.begin(), ws.end(), [](wchar_t ch) { return !iswspace(ch); }));
	// 右側 (rtrim)
	ws.erase(
		find_if(ws.rbegin(), ws.rend(), [](wchar_t ch) { return !iswspace(ch); }).base(),
		ws.end());
	return ref new String(ws.c_str());
}
// Split: 指定した区切り文字で文字列を分割
vector<Platform::String^> SplitString(Platform::String^ input, wchar_t delimiter)
{
	vector<Platform::String^> tokens;
	wstring ws(input->Data());
	// std::wstringstream を用いて区切る
	wstringstream wss(ws);
	wstring token;
	while (getline(wss, token, delimiter))
	{
		tokens.push_back(ref new String(token.c_str()));
	}
	return tokens;
}

ConfirmPage::ConfirmPage()
{
	InitializeComponent();

	auto local = ApplicationData::Current->LocalFolder;
	std::wstring localPath = std::wstring(local->Path->Data()) + L"\\BookingList.csv";

	std::wifstream file(localPath);

	std::wstring line;
	while (std::getline(file, line))
	{
		std::wstringstream ss(line);
		std::wstring number, user, plan, date, people, status, cre;

		std::getline(ss, number, L',');
		std::getline(ss, user, L',');
		std::getline(ss, plan, L',');
		std::getline(ss, date, L',');
		std::getline(ss, people, L',');
		std::getline(ss, status, L',');
		std::getline(ss, cre, L',');

		if (user == L"P01") {
			user = L"北海道";
		}
		else if (user == L"P02")
		{
			user = L"京都";
		}
		else if (user == L"P03")
		{
			user = L"沖縄";
		}
		else
		{
			continue;
		}

		Platform::String^ content = ref new Platform::String(user.c_str());
		Platform::String^ content2 = ref new Platform::String(date.c_str());
		Platform::String^ content3 = ref new Platform::String(people.c_str());
		auto checkBox = ref new Windows::UI::Xaml::Controls::CheckBox();
		checkBox->Content = content + "," + content2 + "," + content3 + "人";
		checkBox->IsChecked = false;
		CheckListBox->Items->Append(checkBox);
	}
}

void ConfirmPage::Delete_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	unsigned int count = CheckListBox->Items->Size;
	int index[100];  // チェックされているアイテムのインデックスを格納
	String^ text1[100];
	int j = 0;

	// チェックされているアイテムを検索
	for (unsigned int i = 0; i < count; ++i)
	{
		auto item = CheckListBox->Items->GetAt(i);
		CheckBox^ cb = dynamic_cast<CheckBox^>(item);  // CheckBoxにキャスト
		if (cb != nullptr && cb->IsChecked->Value)
		{
			//チェックされている値を取得
			String^ label = dynamic_cast<String^>(cb->Content);
			OutputDebugString((label + L" がチェックされています\n")->Data());
			//MyTextBox->Text += label;
			index[j] = i;  // チェックされているアイテムのインデックスを格納
			j++;
		}
		else
		{
			String^ label = dynamic_cast<String^>(cb->Content);
			text1[i] = label;
		}
	}

	//// チェックされているアイテムを削除（逆順で削除する）
	//for (int i = j - 1; i >= 0; --i)  // 配列の要素数 j の逆順でループ
	//{
	//    int idx = index[i];  // 削除対象のインデックス
	//    CheckListBox->Items->RemoveAt(idx);
	//}

	StorageFolder^ folder = ApplicationData::Current->LocalFolder;		//ローカルフォルダの参照
	Platform::String^ dbPath = folder->Path;

	/* IAsyncOperation<StorageFile^>^ fileAsync = folder->CreateFileAsync(
		 L"BookingList.csv", CreationCollisionOption::OpenIfExists); */      //既存ファイルの上書きかファイルの新規作成

	IAsyncOperation<StorageFile^>^ fileAsync = folder->GetFileAsync("BookingList.csv");  //既存ファイルに書き込み


	fileAsync->Completed =
		ref new AsyncOperationCompletedHandler<StorageFile^>(
			[=](IAsyncOperation<StorageFile^>^ fileInfo, AsyncStatus fileStatus)
			{

				if (fileStatus != AsyncStatus::Completed)
				{
					return;
				}

				StorageFile^ file = fileInfo->GetResults();
				fileInfo->Close();

				// 現在の内容を読み取って追記する


				auto linesTask = FileIO::ReadLinesAsync(file);
				linesTask->Completed = ref new AsyncOperationCompletedHandler<IVector<String^>^>(
					[=](IAsyncOperation<IVector<String^>^>^ linesOp, AsyncStatus lineStatus)
					{
						if (lineStatus != AsyncStatus::Completed)
						{
							return;
						}
						auto lines = linesOp->GetResults();
						linesOp->Close();
						std::wstring text = L"ReservationID,UserID,PlanID,ReservationDate,NumberOfPeople,Status,CreatedAt\n";
						String^ newtext;
						unsigned int lineCount;
						int count = 1;
						for (int i = 0; i < 20; i++)
						{
							if (text1[i] != nullptr)
							{
								std::wstring chk = std::wstring(text1[i]->Data());
								std::wstringstream ss(chk);
								std::wstring number, user, plan, date, people, status, cre, num;

								std::getline(ss, user, L',');
								std::getline(ss, date, L',');
								std::getline(ss, people, L',');

								if (user == L"北海道") {
									user = L"P01";
								}
								else if (user == L"京都")
								{
									user = L"P02";
								}
								else if (user == L"沖縄")
								{
									user = L"P03";
								}
								else
								{
									continue;
								}
								std::wstringstream pp(people);
								std::getline(pp, num, L'人');

								number = std::to_wstring(count);

								plan = L"U01";

								status = L"1";

								cre = L"2025/5/21";

								text += number + L',' + user + L',' + plan + L',' + date + L',' + num + L',' + status + L',' + cre + L'\n';
								//newtext = lineCount + "," + text;
								newtext = ref new Platform::String(text.c_str());

								count++;
							}

						}

						auto readTask = FileIO::ReadTextAsync(file);
						readTask->Completed = ref new AsyncOperationCompletedHandler<String^>(
							[=](IAsyncOperation<String^>^ readOp, AsyncStatus readStatus)
							{
								if (readStatus != AsyncStatus::Completed)
								{
									return;
								}


								/*String^ currentText = readOp->GetResults();
								readOp->Close();

								String^ updatedText = currentText + newtext;*/

								// 書き戻し（追記された状態）
								FileIO::WriteTextAsync(file, newtext);
							});
					});

			});
	Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(HomePage::typeid));
}

void ConfirmPage::Back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(HomePage::typeid));

}
