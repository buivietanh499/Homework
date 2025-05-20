#pragma once
#include "LoginPage.g.h"

namespace Group4_project
{
	// LoginPage クラスはログイン画面を表します
	public ref class LoginPage sealed
	{
	public:
		// コンストラクタ
		LoginPage();

	private:
		// ログインボタンがクリックされたときに呼び出されます
		void LoginButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		// メインページに戻るボタンがクリックされたときに呼び出されます
		void GoBackToMainPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		// 登録ページに遷移するボタンがクリックされたときに呼び出されます
		void GoToRegisterPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
