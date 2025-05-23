#include "pch.h"  
#include "HomePage.xaml.h"  
#include "MainPage.xaml.h"  
#include "PlanDetailPage.xaml.h"
#include "Data/UserSession.h"

using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;

HomePage::HomePage()
{
	InitializeComponent();
	// Hiển thị tên người dùng
	if (UserSession::IsLoggedIn)
	{
		UserNameTextBlock->Text = "ようこそ、" + UserSession::CurrentUserName + L" さん";
	}
	else
	{
		UserNameTextBlock->Text = "ようこそ、ゲスト さん";
	}
}
// Nếu bạn muốn cập nhật tên user mỗi lần vào trang
void HomePage::OnNavigatedTo(NavigationEventArgs^ e)
{
	Page::OnNavigatedTo(e);
	if (UserSession::IsLoggedIn)
	{
		UserNameTextBlock->Text = "ようこそ、" + UserSession::CurrentUserName + L" さん";
	}
	else
	{
		UserNameTextBlock->Text = "ようこそ、ゲスト さん";
	}
}
void HomePage::Logout_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MainPage::typeid));
}

void HomePage::Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PlanDetailPage::typeid));;
}
