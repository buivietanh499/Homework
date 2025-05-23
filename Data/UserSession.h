//#pragma once
//namespace Group4_project
//{
//	public ref class UserSession sealed
//	{
//	public:
//		static Platform::String^ CurrentUserID;
//		static Platform::String^ CurrentUserName;
//		static Platform::String^ CurrentUserEmail;
//		static bool IsLoggedIn;
//		static void SetUserInfo(Platform::String^ userID, Platform::String^ userName, Platform::String^ userEmail)
//		{
//			CurrentUserID = userID;
//			CurrentUserName = userName;
//			CurrentUserEmail = userEmail;
//			IsLoggedIn = true;
//		}
//		static void Logout()
//		{
//			CurrentUserID = nullptr;
//			CurrentUserName = nullptr;
//			CurrentUserEmail = nullptr;
//			IsLoggedIn = false;
//		}
//	};
//}