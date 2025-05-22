#include "pch.h"
#include "UserDataHelper.h"
#include <fstream>
#include <sstream>
#include <Windows.Storage.h>
#include <Windows.ApplicationModel.h>
using namespace Windows::Storage;
using namespace Windows::ApplicationModel;
// Đọc danh sách user từ file CSV
std::vector<User> UserDataHelper::LoadUsers()
{
	std::vector<User> users;
	try
	{
		auto localFolder = ApplicationData::Current->LocalFolder;
		std::wstring localPath = std::wstring(localFolder->Path->Data()) + L"\\users.csv";
		std::wifstream file(localPath);
		if (!file.is_open())
			return users;
		std::wstring line;
		// Bỏ qua dòng đầu tiên (header)
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::wstringstream ss(line);
			std::wstring idStr, email, password, name;
			std::getline(ss, idStr, L',');
			std::getline(ss, email, L',');
			std::getline(ss, password, L',');
			std::getline(ss, name, L',');
			if (!email.empty())
			{
				int id = std::stoi(idStr);
				users.push_back({ id, email, password, name });
			}
		}
	}
	catch (...) {}
	return users;
}
// Kiểm tra email đã tồn tại chưa
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
// Lưu user mới vào file CSV
bool UserDataHelper::SaveUser(const User& user)
{
	try
	{
		auto folder = ApplicationData::Current->LocalFolder;
		std::wstring path = folder->Path->Data() + std::wstring(L"\\users.csv");
		bool fileExists = false;
		{
			std::wifstream checkFile(path);
			fileExists = checkFile.is_open();
		}
		// Lấy ID lớn nhất hiện tại
		auto users = LoadUsers();
		int newId = 1;
		if (!users.empty())
			newId = users.back().id + 1;
		std::wofstream file(path, std::ios::app);
		if (file.is_open())
		{
			// Nếu file chưa có, ghi header trước
			if (!fileExists)
			{
				file << L"id,email,password,name" << std::endl;
			}
			// Ghi user với ID mới
			file << newId << L"," << user.email << L"," << user.password << L"," << user.name << std::endl;
			return true;
		}
	}
	catch (...) {}
	return false;
}
