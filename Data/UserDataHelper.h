#pragma once
#include <string>
#include <vector>

// ユーザー情報を表す構造体
struct User
{
	std::wstring email;    // メールアドレス
	std::wstring password; // パスワード
	std::wstring name;     // 名前
};

// ユーザーデータの読み書きを補助するクラス
class UserDataHelper
{
public:
	// ユーザー一覧を読み込む
	static std::vector<User> LoadUsers();
	// ユーザー情報を保存する
	static bool SaveUser(const User& user);
};
