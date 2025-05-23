//
// TravelBook.xaml.h
// TravelBook クラスの宣言
//

#pragma once

#include "TravelBookPage.g.h"

namespace Group4_project
{
	/// <summary>
	/// それ自体で使用できる空白ページまたはフレーム内に移動できる空白ページ。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
		public ref class TravelBookPage sealed
	{
	public:
		TravelBookPage();
	private:
		void Sign_up_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DestinationBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void PlanBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void TextBox1_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
	};
}
