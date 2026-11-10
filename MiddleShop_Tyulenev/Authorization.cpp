#include "Authorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentStatus == L"SuperAdmin")
			{

			}
			else if (currentStatus == L"Admin")
			{

			}
			else if (currentStatus == L"User")
			{

			}
			else
			{
				std::wcerr << L"\n\n_CURRENT_STATUS_LOGIN_ERROR_\n\n";
			}
		}
		else
		{
			system("cls");
			std::wcout << L"\n\n\n\t\t\tДомой спать WW\n\n\n";
			Sleep(1000);
			break;
		}
	}
}

bool Login()
{
	std::wstring login, pass;

	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать!\n\n\t\t\t CS-MARKET\n\n\n";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);

			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"\nДобро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}
