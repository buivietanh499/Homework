#pragma once  
#include "RegisterPage.g.h"  

namespace Group4_project
{
	public ref class RegisterPage sealed
	{
	public:
		RegisterPage();
	private:
		void RegisterButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GoToLoginPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GoBackToMainPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
