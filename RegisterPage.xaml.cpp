#include "pch.h"
#include "RegisterPage.xaml.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>
#include <regex>
#include "Data/UserDataHelper.h"

using namespace Windows::UI::Xaml::Interop;
using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace concurrency;
void RegisterPage::RegisterButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	std::wstring email = EmailTextBox->Text->Data();
	std::wstring name = NameTextBox->Text->Data();
	std::wstring password = PasswordTextBox->Password->Data();
	std::wstring confirmPassword = ConfirmPasswordTextBox->Password->Data();
	if (email.empty() || name.empty() || password.empty() || confirmPassword.empty())
	{
		ContentDialog^ dialog = ref new ContentDialog();
		dialog->Title = "入力エラー";
		dialog->Content = "すべての項目を入力してください。";
		dialog->CloseButtonText = "OK";
		dialog->ShowAsync();
		return;
	}
	std::wregex emailRegex(LR"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
	if (!std::regex_match(email, emailRegex))
	{
		ContentDialog^ dialog = ref new ContentDialog();
		dialog->Title = "入力エラー";
		dialog->Content = "正しいメールアドレスを入力してください。";
		dialog->CloseButtonText = "OK";
		dialog->ShowAsync();
		return;
	}
	if (password.length() < 3)
	{
		ContentDialog^ dialog = ref new ContentDialog();
		dialog->Title = "入力エラー";
		dialog->Content = "パスワードは3文字以上で入力してください。";
		dialog->CloseButtonText = "OK";
		dialog->ShowAsync();
		return;
	}
	if (password != confirmPassword)
	{
		ContentDialog^ dialog = ref new ContentDialog();
		dialog->Title = "入力エラー";
		dialog->Content = "パスワードと確認用パスワードが一致しません。";
		dialog->CloseButtonText = "OK";
		dialog->ShowAsync();
		return;
	}
	User newUser{ email, password, name };
	if (UserDataHelper::SaveUser(newUser))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
	else
	{
		ContentDialog^ dialog = ref new ContentDialog();
		dialog->Title = "エラー";
		dialog->Content = "アカウントを保存できませんでした。";
		dialog->CloseButtonText = "OK";
		dialog->ShowAsync();
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
RegisterPage::RegisterPage()
{
	InitializeComponent();
}





