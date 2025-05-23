#include "pch.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"
#include "HomePage.xaml.h"
#include "RegisterPage.xaml.h"
#include "Data/UserSession.h"
#include <Windows.UI.Xaml.Interop.h>
#include <Data/UserDataHelper.h>
using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
// Hàm hiển thị dialog thông báo
void ShowDialog(String^ title, String^ content)
{
	ContentDialog^ dialog = ref new ContentDialog();
	dialog->Title = title;
	dialog->Content = content;
	dialog->CloseButtonText = "OK";
	dialog->ShowAsync();
}
// Constructor
LoginPage::LoginPage()
{
	InitializeComponent();
}
// Xử lý khi nhấn nút Login
void LoginPage::LoginButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	std::wstring email = EmailTextBox->Text->Data();
	std::wstring password = PasswordTextBox->Password->Data();
	auto users = UserDataHelper::LoadUsers();
	for (const auto& user : users)
	{
		if (user.email == email && user.password == password)
		{
			// Lưu thông tin người dùng vào UserSession
			UserSession::SetUserInfo(
				ref new Platform::String(user.id.c_str()),
				ref new Platform::String(user.name.c_str()),
				ref new Platform::String(user.email.c_str())
			);
			this->Frame->Navigate(TypeName(HomePage::typeid));
			return;
		}
	}
	ShowDialog("ログインに失敗しました", "メールアドレスまたはパスワードが間違っています。");
}
void LoginPage::GoBackToMainPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid));
}
void LoginPage::GoToRegisterPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(RegisterPage::typeid));
}
