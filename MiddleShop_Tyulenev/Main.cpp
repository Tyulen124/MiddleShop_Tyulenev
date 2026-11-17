#include "Authorization.hpp"
#include <io.h>
#include <fcntl.h>



int main()
{

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	Start();







	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	delete[]userIdArr;

	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]priceArr;
		delete[]countArr;
	}




	return 0;
}
/*
аккаунты: супер админ, администратор, пользователь
функции добавления учётки, удаления, редактирования
авторизация: ввод логина и пароля,смена учётных записей
склад: баз данных, редактирование склада
продажи: покупка, чеки, оплата*

служебные_функции: всяка для работы программы












*/