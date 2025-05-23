#include "pch.h"  
#include "HomePage.xaml.h"  
#include "MainPage.xaml.h"  
#include "PlanDetailPage.xaml.h"
#include "TravelBookPage.xaml.h"
#include "Data/UserSession.h"
#include "ConfirmPage.xaml.h"

using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;

HomePage::HomePage()
{
	InitializeComponent();

	if (UserSession::IsLoggedIn)
	{
		UserNameTextBlock->Text = "ようこそ、" + UserSession::CurrentUserName + L" さん";
	}
	else
	{
		UserNameTextBlock->Text = "ようこそ、ゲスト さん";
	}
}

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

void HomePage::PlanDetailPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PlanDetailPage::typeid));;
}

void HomePage::TravelBookPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(TravelBookPage::typeid));;
}

void HomePage::ConfirmPage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(ConfirmPage::typeid));
}

