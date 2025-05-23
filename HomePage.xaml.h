#pragma once
#include "HomePage.g.h"

namespace Group4_project
{
	public ref class HomePage sealed
	{
	public:
		HomePage();
		void Logout_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	};
}
