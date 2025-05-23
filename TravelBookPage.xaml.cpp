/****************************************************/
/*ファイル名: TravelBook.xaml.cpp  					*/
/*概要　　　: TravelBookPage     					*/
/*作成者　　: Aoi Kobari		    				*/
/*日付　　　: 2025/05/19			        		*/
/*OS　　　　：Windows11 Pro		            		*/
/*バージョン: Visual studio 2022		     		*/
/****************************************************/

//
// TravelBook.xaml.cpp
// TravelBook クラスの実装
//

#include "pch.h"
#include "TravelBookPage.xaml.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>
#include <chrono> // chronoライブラリをインクルード
#include <iomanip> // 入出力のフォーマットを整えるために必要
#include  "Data/UserSession.h"

using namespace Group4_project;

using namespace Platform;
using namespace std;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Storage;

// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=234238 を参照してください

/*-----------------------------------------
関数名：TravelBook
概要　：TravelBookのコンストラクタ・初期化
戻り値：合計後の数字
引数　：なし
------------------------------------------*/
TravelBookPage::TravelBookPage()
{
	InitializeComponent();
	//登録内容表示欄の初期化
	SelectedText->Text = "";
}

/*-----------------------------------------
関数名：Sign_up_Click
概要　：登録ボタン押下処理
戻り値：なし
引数　：Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e
------------------------------------------*/
void TravelBookPage::Sign_up_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Array<String^>^ ary = { "P01", "P02", "P03" };		//PlanID用配列
	Sign_up->IsEnabled = false;

	Windows::UI::Xaml::Controls::ComboBoxItem^ cmb_selected1;	//コンボボックス1のアイテム
	Windows::UI::Xaml::Controls::ComboBoxItem^ cmb_selected2;	//コンボボックス2のアイテム
	if (DestinationBox->SelectedItem != nullptr && PlanBox->SelectedItem != nullptr && TextBox1->Text != "")
	{
		cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
		cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程

		//人数の取得と数値型変換
		auto text_box = TextBox1->Text;
		std::wstring wstr(text_box->Data());
		int nop = stoi(wstr);

		//人数入力チェック
		if (nop > 10)
		{
			ErrorMsgBox->Text = "* 入力内容に誤りがあります";
			TextBox1->Text = "";
			Sign_up->IsEnabled = true;
			return;
		}
		else if (nop < 0)
		{
			ErrorMsgBox->Text = "* 入力内容に誤りがあります";
			TextBox1->Text = "";
			Sign_up->IsEnabled = true;
			return;
		}


	}
	else
	{
		//未選択・未入力エラーチェック
		if (DestinationBox->SelectedItem == nullptr)
		{
			ErrorMsgBox->Text = "* プランを選択してください。";
		}
		else if (PlanBox->SelectedItem == nullptr)
		{
			ErrorMsgBox->Text = "* 日程を選択してください。";
		}
		else
		{
			ErrorMsgBox->Text = "* 人数は必須項目です。";
		}
		Sign_up->IsEnabled = true;
		return;
	}

	auto select_num = DestinationBox->SelectedIndex;		//選択された行先の行番号
	auto plan_id = ary[select_num];
	//プランID
	String^ user_id = UserSession::CurrentUserID;								//仮のユーザーID

	// 現在の日付を取得
	auto now = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);
	std::tm local_time;
	localtime_s(&local_time, &current_time);
	std::stringstream ss;
	ss << std::put_time(&local_time, "%Y/%m/%d");
	string format_time = ss.str();
	Platform::String^ platform_time = ref new Platform::String(std::wstring(format_time.begin(), format_time.end()).c_str());

	String^ text = user_id + "," + plan_id + "," + cmb_selected2->Content->ToString() + ","
		+ TextBox1->Text + "," + "1," + platform_time + "\n"; // csvに書き込むテキスト

	//CSV書き込み処理
	StorageFolder^ folder = ApplicationData::Current->LocalFolder;		//ローカルフォルダの参照

	IAsyncOperation<StorageFile^>^ file_async = folder->CreateFileAsync(
		L"BookingList.csv", CreationCollisionOption::OpenIfExists);

	file_async->Completed =
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
				auto line_task = FileIO::ReadLinesAsync(file);
				line_task->Completed = ref new AsyncOperationCompletedHandler<IVector<String^>^>(
					[=](IAsyncOperation<IVector<String^>^>^ linesOp, AsyncStatus lineStatus)
					{
						//現在の行数をカウントする
						if (lineStatus != AsyncStatus::Completed)
						{
							return;
						}
						auto lines = linesOp->GetResults();
						linesOp->Close();

						unsigned int line_count = lines->Size;	//行数カウント変数
						String^ new_text = line_count + "," + text;

						//書き戻し処理
						auto read_task = FileIO::ReadTextAsync(file);
						read_task->Completed = ref new AsyncOperationCompletedHandler<String^>(
							[=](IAsyncOperation<String^>^ readOp, AsyncStatus readStatus)
							{
								if (readStatus != AsyncStatus::Completed)
								{
									return;
								}

								String^ current_text = readOp->GetResults();
								readOp->Close();

								String^ updated_text = current_text + new_text;

								FileIO::WriteTextAsync(file, updated_text);
							});
					});

			});

	//登録完了ダイアログ表示
	Windows::UI::Popups::MessageDialog^ md =
		ref new Windows::UI::Popups::MessageDialog(
			"プラン：" + cmb_selected1->Content->ToString() + "\n" +
			"日程：" + cmb_selected2->Content->ToString() + "\n" +
			"人数：" + TextBox1->Text + " 人" + L"\n\nこの内容で登録が完了しました！");

	md->ShowAsync();
	// 画面の遷移
	if (this->Frame->CanGoBack)
	{
		this->Frame->GoBack();
	}
}

/*-----------------------------------------
関数名：Back_Click
概要　：戻るボタン押下処理
戻り値：なし
引数　：Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e
------------------------------------------*/
void TravelBookPage::Back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//テキストが登録されている場合本当に戻ってよいかの処理。
	//各コントロールの情報を取得
	auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);
	auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);
	auto text_box = TextBox1->Text;
	if (cmb_selected1 != nullptr || cmb_selected2 != nullptr)
	{
		//待機後、メッセージでキャンセルを押すと元の画面に戻るように。
		Windows::UI::Popups::MessageDialog^ md =
			ref new Windows::UI::Popups::MessageDialog("登録内容を破棄してホームに戻ります", "確認");

		md->ShowAsync();
	}
	// 1つ戻る
	if (this->Frame->CanGoBack)
	{
		this->Frame->GoBack();
	}
}

/*-----------------------------------------
関数名：DestinationBox_SelectionChanged
概要　：プランコンボボックスイベント
戻り値：なし
引数　：Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e
------------------------------------------*/
void TravelBookPage::DestinationBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	//プランの自動表示
	if (SelectedText->Text == "")
	{
		auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
		SelectedText->Text = "プラン：" + SelectedText->Text + cmb_selected1->Content->ToString() + "\n";
	}
	else
	{
		SelectedText->Text = "";
		if (PlanBox->SelectedItem == nullptr)
		{
			auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
			SelectedText->Text = "プラン：" + SelectedText->Text + cmb_selected1->Content->ToString() + "\n";
		}
		else
		{
			auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
			auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程
			auto text_box = TextBox1->Text;
			SelectedText->Text = SelectedText->Text + "プラン：" + cmb_selected1->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "日程：" + cmb_selected2->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "人数：" + text_box + "人" + "\n";
		}
	}

}

/*-----------------------------------------
関数名：PlanBox_SelectionChanged
概要　：日程コンボボックス選択イベント
戻り値：なし
引数　：Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e
------------------------------------------*/
void TravelBookPage::PlanBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	//日付の自動表示
	if (SelectedText->Text == "")
	{
		auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程
		SelectedText->Text = SelectedText->Text + "日程：" + cmb_selected2->Content->ToString() + "\n";
	}
	else
	{
		SelectedText->Text = "";
		if (DestinationBox->SelectedItem == nullptr)
		{
			auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程
			SelectedText->Text = SelectedText->Text + "日程：" + cmb_selected2->Content->ToString() + "\n";
		}
		else
		{
			auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
			auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程
			auto text_box = TextBox1->Text;
			SelectedText->Text = SelectedText->Text + "プラン：" + cmb_selected1->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "日程：" + cmb_selected2->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "人数：" + text_box + "人" + "\n";
		}
	}

}

/*-----------------------------------------
関数名：PlanBox_SelectionChanged
概要　：テキストボックス入力イベント
戻り値：なし
引数　：Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e
------------------------------------------*/
void TravelBookPage::TextBox1_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	//人数の自動表示
	if (SelectedText->Text == "")
	{
		auto text_box = TextBox1->Text;
		SelectedText->Text = SelectedText->Text + "人数：" + text_box + "人" + "\n";
	}
	else
	{
		if (DestinationBox->SelectedItem != nullptr && PlanBox->SelectedItem != nullptr)
		{
			SelectedText->Text = "";
			auto cmb_selected1 = dynamic_cast<ComboBoxItem^>(DestinationBox->SelectedItem);	//選択した行先
			auto cmb_selected2 = dynamic_cast<ComboBoxItem^>(PlanBox->SelectedItem);			//選択した日程
			auto text_box = TextBox1->Text;
			SelectedText->Text = SelectedText->Text + "プラン：" + cmb_selected1->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "日程：" + cmb_selected2->Content->ToString() + "\n";
			SelectedText->Text = SelectedText->Text + "人数：" + text_box + "人" + "\n";
		}
	}
}
