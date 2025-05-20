#pragma once
#include "MainPage.g.h"

namespace Group4_project
{
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void LoginButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void RegisterButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
