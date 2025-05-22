#pragma once
#include <string>
#include <vector>

// ユーザー情報を表す構造体
struct User
{
	int id;
	std::wstring email;
	std::wstring password;
	std::wstring name;
};

// ユーザーデータの読み書きを補助するクラス
class UserDataHelper
{
public:
	static std::vector<User> LoadUsers();
	static bool IsEmailExists(const std::wstring& email);
	static bool SaveUser(const User& user);
};
