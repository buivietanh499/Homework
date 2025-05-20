#include "pch.h"
#include "UserDataHelper.h"
#include <fstream>
#include <sstream>
#include <Windows.Storage.h>
#include <Windows.ApplicationModel.h>

using namespace Windows::Storage;
using namespace Windows::ApplicationModel;

std::vector<User> UserDataHelper::LoadUsers()
{
	std::vector<User> users;

	try
	{
		// ローカルフォルダーからusers.csvを探す
		auto localFolder = ApplicationData::Current->LocalFolder;
		std::wstring localPath = std::wstring(localFolder->Path->Data()) + L"\\users.csv";

		std::wifstream file(localPath);
		if (!file.is_open())
		{
			// プロジェクトのDataフォルダーから探す
			file.open(L"Data\\users.csv");

			if (!file.is_open())
			{
				// インストールフォルダーのDataフォルダーから探す
				auto installFolder = Package::Current->InstalledLocation;
				std::wstring assetPath = std::wstring(installFolder->Path->Data()) + L"\\Data\\users.csv";
				file.open(assetPath);

				if (!file.is_open())
				{
					// どこにもファイルがなければ例外
					throw std::runtime_error("Cannot open users.csv from any location");
				}
			}
		}

		std::wstring line;
		while (std::getline(file, line))
		{
			std::wstringstream ss(line);
			std::wstring email, password, name;

			std::getline(ss, email, L',');
			std::getline(ss, password, L',');
			std::getline(ss, name, L',');

			if (!email.empty())
			{
				// ユーザー情報をベクターに追加
				users.push_back({ email, password, name });
			}
		}
	}
	catch (...) {}

	return users;
}

bool UserDataHelper::IsEmailExists(const std::wstring& email)
{
	auto folder = ApplicationData::Current->LocalFolder;
	std::wstring path = folder->Path->Data() + std::wstring(L"\\users.csv");
	std::wifstream file(path + L"\\users.csv");
	std::wstring line;
	while (std::getline(file, line))
	{
		auto pos = line.find(L",");
		if (pos != std::wstring::npos)
		{
			std::wstring storedEmail = line.substr(0, pos);
			if (storedEmail == email)
			{
				return true;
			}
		}
	}
	return false;
}

bool UserDataHelper::SaveUser(const User& user)
{
	try
	{
		// ローカルフォルダーのusers.csvに追記
		auto folder = ApplicationData::Current->LocalFolder;
		std::wstring path = folder->Path->Data() + std::wstring(L"\\users.csv");

		std::wofstream file(path, std::ios::app);
		if (file.is_open())
		{
			file << user.email << L"," << user.password << L"," << user.name << std::endl;
			return true;
		}
	}
	catch (...) {}

	return false;
}
