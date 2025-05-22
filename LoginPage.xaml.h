#pragma once
#include "LoginPage.g.h"

namespace Group4_project
{
	// LoginPage クラスはログイン画面を表します
	public ref class LoginPage sealed
	{
	public:
		LoginPage();

	private:
		void LoginButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GoBackToMainPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GoToRegisterPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
