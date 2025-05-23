#pragma once
#include "ConfirmPage.g.h"
namespace Group4_project
{
	public ref class ConfirmPage sealed
	{
	public:
		ConfirmPage();
	private:
		void Delete_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}