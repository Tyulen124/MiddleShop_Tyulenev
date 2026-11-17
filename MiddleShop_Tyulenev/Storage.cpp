#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 size_t maxStorageSize = 1000000;
  size_t currentStorageSize = 0;

 void CreateStorage(int mode)
 {
	 if (mode == 0 && !isStorageCreated )
	 {
		 const size_t staticSize = 10;

		 size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
		 std::wstring nameArrStatic[staticSize]
		 {
			 L"Керамбит Волны",L"Нож-Бабочка Волны",L"Штык-Нож М9 Легенды",L"Штык-Нож Легенды",L"AWP Dragon Lore",L"AWP Gungnir",L"M4 Вой",L"AK-47 Огненый змей",
			 L"Спортивные-Перчатки Ящик Пандоры",L"USP Неонуар"
		 };
		 size_t countArrStatic[staticSize]{ 8,9,23,14,6,5,7,19,11,35 };
		 double priceArrStatic[staticSize]{ 500000, 560000, 220000, 180000,800000, 910000,764000,311556,131132,2100, };

		 sizeSt = staticSize;
		 idArr = new size_t[sizeSt];
		 nameArr = new std::wstring[sizeSt];
		 countArr = new size_t[sizeSt];
		 priceArr = new double[sizeSt];

		 FillArray(idArr, idArrStatic, sizeSt);
		 FillArray(nameArr, nameArrStatic, sizeSt);
		 FillArray(countArr, countArrStatic, sizeSt);
		 FillArray(priceArr, priceArrStatic, sizeSt);
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 currentStorageSize += countArrStatic[i];
		 }
		 isStorageCreated = true;
	 }
	 else if (mode == 1)
	 {

	 }
	 else
	 {
		 std::wcout << L"Склад уже создан\n\n";
	 }
 }

 void ShowStorage(int mode)
 {
	 if (mode == 0)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tСписок Товаров\n\n";

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			 << L"Кол-во\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		 }
	
		 std::wcout << L"\n\n";
		 system("pause");
	 }
	 else if (mode == 1)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tПополнение Товаров\n\n";

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			 << L"Кол-во\t";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" ;
		 }

		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			 << maxStorageSize << L"\n\n";
	 }

 }
 void AddProduct()
 {
	 std::wstring chooseId, chooseCount, choose;
	 int id = 0;
	 size_t count = 0;

	 while (true)
	 {

		 ShowStorage(1);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции пополнения товара\n\n";
		 }
		 else if (isNumber(chooseId))
		 {
			 id = std::stoi(chooseId) - 1;
			 if (id < 0 || id > sizeSt - 1)
			 {
				 Err();
			 }
			 else
			 {
				 std::wcout << L"Введите кол-во товара для пополнения: ";
				 Getline(chooseCount);
				 if (isNumber(chooseCount))
				 {
					 count = std::stoull(chooseCount); 
					 
				 }
			 }
		 }



	 }
 }
