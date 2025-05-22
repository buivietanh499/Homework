#pragma once

#include "PlanDetailPage.g.h"
#include "Windows.UI.Xaml.Controls.h"  // ScrollViewer を使うために必要

namespace Group4_project
{
	public ref class PlanDetailPage sealed
	{
	public:
		PlanDetailPage();

	private:
		void ShowImage1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ShowImage8_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PrevPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NextPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void UpdatePage();
		void HomePage_click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		// メンバー変数
		int currentPage = 1;

		// ScrollViewer をコードビハインドでアクセスできるように宣言
		Windows::UI::Xaml::Controls::ScrollViewer^ MainScrollViewer2;

	};
}

