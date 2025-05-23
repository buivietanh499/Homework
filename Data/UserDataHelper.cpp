﻿#include "pch.h"
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
		auto localFolder = ApplicationData::Current->LocalFolder;
		std::wstring localPath = std::wstring(localFolder->Path->Data()) + L"\\users.csv";
		std::wifstream file(localPath);
		if (!file.is_open())
		{
			return users;
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
				users.push_back({ email, password, name });
			}
		}
	}
	catch (...)
	{
	}
	return users;
}
bool UserDataHelper::IsEmailExists(const std::wstring& email)
{
	auto users = LoadUsers();
	for (const auto& user : users)
	{
		if (user.email == email)
			return true;
	}
	return false;
}
bool UserDataHelper::SaveUser(const User& user)
{
	try
	{
		auto folder = ApplicationData::Current->LocalFolder;
		std::wstring path = folder->Path->Data() + std::wstring(L"\\users.csv");
		std::wofstream file(path, std::ios::app);
		if (file.is_open())
		{
			file << user.email << L"," << user.password << L"," << user.name << std::endl;
			return true;
		}
	}
	catch (...)
	{
	}
	return false;
}