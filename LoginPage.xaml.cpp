#include "pch.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"
#include "HomePage.xaml.h"
#include "RegisterPage.xaml.h"
#include <Windows.UI.Xaml.Interop.h>
#include <Data/UserDataHelper.h>
using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
LoginPage::LoginPage()
{
	InitializeComponent();
}
void LoginPage::LoginButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	std::wstring email = EmailTextBox->Text->Data();
	std::wstring password = PasswordTextBox->Password->Data();
	auto users = UserDataHelper::LoadUsers();
	for (auto& user : users)
	{
		if (user.email == email && user.password == password)
		{
			this->Frame->Navigate(TypeName(HomePage::typeid));
			return;
		}
	}
	ContentDialog^ dialog = ref new ContentDialog();
	dialog->Title = "ログインに失敗しました";
	dialog->Content = "メールアドレスまたはパスワードが間違っています。";
	dialog->CloseButtonText = "OK";
	dialog->ShowAsync();
}
void LoginPage::GoBackToMainPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid));
}
void LoginPage::GoToRegisterPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(RegisterPage::typeid));
}






