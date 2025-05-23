#include "pch.h"
#include "RegisterPage.xaml.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>
#include <regex>
#include <Data/UserDataHelper.h>
using namespace Windows::UI::Xaml::Interop;
using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace concurrency;
RegisterPage::RegisterPage()
{
	InitializeComponent();
}
void ShowErrorDialog(String^ title, String^ content)
{
	ContentDialog^ dialog = ref new ContentDialog();
	dialog->Title = title;
	dialog->Content = content;
	dialog->CloseButtonText = "OK";
	dialog->ShowAsync();
}
void RegisterPage::RegisterButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	std::wstring email = EmailTextBox->Text->Data();
	std::wstring name = NameTextBox->Text->Data();
	std::wstring password = PasswordTextBox->Password->Data();
	std::wstring confirmPassword = ConfirmPasswordTextBox->Password->Data();
	if (email.empty() || name.empty() || password.empty() || confirmPassword.empty())
	{
		ShowErrorDialog("入力エラー", "すべての項目を入力してください。");
		return;
	}
	std::wregex emailRegex(LR"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
	if (!std::regex_match(email, emailRegex))
	{
		ShowErrorDialog("入力エラー", "正しいメールアドレスを入力してください。");
		return;
	}
	if (password.length() < 3)
	{
		ShowErrorDialog("入力エラー", "パスワードは3文字以上で入力してください。");
		return;
	}
	if (password != confirmPassword)
	{
		ShowErrorDialog("入力エラー", "パスワードと確認用パスワードが一致しません。");
		return;
	}
	// Kiểm tra email trùng lặp
	if (UserDataHelper::IsEmailExists(email))
	{
		ShowErrorDialog("入力エラー", "このメールアドレスはすでに使用されています。");
		return;
	}
	// ID sẽ được UserDataHelper tự sinh dưới dạng P01, P02,...
	User newUser{ L"", email, password, name };
	if (UserDataHelper::SaveUser(newUser))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
	else
	{
		ShowErrorDialog("エラー", "アカウントを保存できませんでした。");
	}
}
void RegisterPage::GoToLoginPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(LoginPage::typeid));
}
void RegisterPage::GoBackToMainPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid));
}