#include "pch.h"  
#include "HomePage.xaml.h"  
#include "MainPage.xaml.h"  
#include "PlanDetailPage.xaml.h"

using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;

HomePage::HomePage()
{
	InitializeComponent();
}

void HomePage::Logout_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MainPage::typeid));
}

void HomePage::Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PlanDetailPage::typeid));;
}
