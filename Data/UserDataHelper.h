#pragma once
#include <string>
#include <vector>
struct User
{
	std::wstring id;
	std::wstring email;
	std::wstring password;
	std::wstring name;
};
class UserDataHelper
{
public:
	static std::vector<User> LoadUsers();
	static bool IsEmailExists(const std::wstring& email);
	static bool SaveUser(const User& user);
};