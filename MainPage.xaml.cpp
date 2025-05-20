#include "pch.h"
#include "MainPage.xaml.h"
#include "LoginPage.xaml.h"
#include "RegisterPage.xaml.h"

using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml::Interop;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

MainPage::MainPage()
{
	InitializeComponent();
}

void MainPage::LoginButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(LoginPage::typeid));
}

void MainPage::RegisterButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(RegisterPage::typeid));
}

void Group4_project::MainPage::TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
