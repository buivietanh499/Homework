#pragma once
#include <string>

namespace Group4_project
{
	public ref class UserSession sealed
	{
	public:
		// Khai báo static property mà không khởi tạo trực tiếp
		static property Platform::String^ CurrentUserID;
		static property Platform::String^ CurrentUserName;
		static property Platform::String^ CurrentUserEmail;
		static property bool IsLoggedIn;

		// Phương thức thiết lập thông tin người dùng
		static void SetUserInfo(Platform::String^ userID, Platform::String^ userName, Platform::String^ userEmail)
		{
			CurrentUserID = userID;
			CurrentUserName = userName;
			CurrentUserEmail = userEmail;
			IsLoggedIn = true;
		}

		// Phương thức đăng xuất
		static void Logout()
		{
			CurrentUserID = nullptr;
			CurrentUserName = nullptr;
			CurrentUserEmail = nullptr;
			IsLoggedIn = false;
		}

	private:
		// Khởi tạo tĩnh (static constructor)
		static void Initialize()
		{
			CurrentUserID = nullptr;
			CurrentUserName = nullptr;
			CurrentUserEmail = nullptr;
			IsLoggedIn = false;
		}
	};
}