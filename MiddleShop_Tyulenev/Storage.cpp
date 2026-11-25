#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 size_t maxStorageSize = 1000000;
  size_t currentStorageSize = 0;

  double maxPrice = 5000000;

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

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			 << L"Кол-во\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		 }
	
		 std::wcout << L"\n\n";
		 system("pause");
	 }
	 else if (mode == 1)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tПополнение Товаров\n\n";

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			 << L"Кол-во\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				  << countArr[i] << L"\n" ;
		 }

		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			 << maxStorageSize << L"\n\n";
	 }
	 else if (mode == 2)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tСписание Товаров\n\n";

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			 << L"Кол-во\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << countArr[i] << L"\n";
		 }

		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			 << maxStorageSize << L"\n\n";
	 }
	 else if (mode == 3)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tИзменение цены\n\n";

		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			 << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				 << std::setprecision(2) << priceArr[i] << L"\n";
		 }

		 std::wcout << L"\n\n";

		 
	 }
	 else if (mode == 4)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tИзменение названия товара\n\n";

		 std::wcout << L"ID\t" <<   L"Название товара\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t"  << std::left << std::setw(40) << nameArr[i]
				  << L"\n";
		 }

		 std::wcout << L"\n\n";


	 }
	 else if (mode == 5)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tУдаление товара\n\n";

		 std::wcout << L"ID\t" << L"Название товара\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << L"\n";
		 }

		 std::wcout << L"\n\n";


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
					 if (count > maxStorageSize - currentStorageSize || count < 0)
					 {
						 std::wcout << L"Некорректное кол-во! На складе осталось "
							 << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								 << countArr[id] + count << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Товар успешно пополнен\n\n";
								 countArr[id] += count;
								 currentStorageSize += count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }



	 }
 }

 void RemoveProduct()
 {
	 std::wstring chooseId, chooseCount, choose;
	 int id = 0;
	 size_t count = 0;

	 while (true)
	 {

		 ShowStorage(2);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции списания товара\n\n";
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
				 std::wcout << L"Введите кол-во товара для списания: ";
				 Getline(chooseCount);
				 if (isNumber(chooseCount))
				 {
					 count = std::stoull(chooseCount);
					 if (count < 0 || count > countArr[id])
					 {
						 std::wcout << L"Некорректное кол-во! На складе осталось "
							 << countArr[id] << L" ед. товара\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								 << countArr[id] - count << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Товар успешно списан\n\n";
								 countArr[id] -= count;
								 currentStorageSize -= count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }



	 }
 }

 void ChangePrice()
 {
	 std::wstring chooseId, choosePrice, choose;
	 int id = 0;
	 double price = 0;

	 while (true)
	 {

		 ShowStorage(3);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции изменения цены\n\n";
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
				 std::wcout << L"Введите новую цену товара: ";
				 Getline(choosePrice);
				 if (isNumber(choosePrice))
				 {
					 price = std::stod(choosePrice);
					 if (price < 0 || price > maxPrice)
					 {
						 std::wcout << L"Некорректная цена! Максимально возмжная цена: "
							 << maxPrice << L" рублей\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> "
								 << price << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Успешное изменение цены\n\n";
								 priceArr[id] = price;
								 // :)
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }



	 }
 }

 void ChangeStorage()
 {
	 std::wstring choose;

	 while (true)
	 {

		 system("cls");

		 std::wcout << L"\n\n\t\t\tРедактирование склада \n\n";
		 std::wcout << L"1 - Добавить новый товар\n";
		 std::wcout << L"2 - Изменить название товара\n";
		 std::wcout << L"3 - Удаление товара\n";
		 std::wcout << L"4 - Изменить лимиты склада\n";
		 std::wcout << L"0 - Выход\n";
		 std::wcout << L"Ввод: ";
		 Getline(choose);
		 if (choose == L"1")
		 {
			 AddNewProduct();
		 }
		 else if (choose == L"2" && sizeSt > 0)
		 {
			 ChangeProductName();
		 }
		 else if (choose == L"3" && sizeSt > 0)
		 {
			 DeleteProduct();
		 }
		 else if (choose == L"4")
		 {

		 }
		 else if (choose == L"0")
		 {
			 std::wcout << L"Выход из редактора склада\n";
			 Sleep(1500);
			 break;
		 }
		 else
		 {
			 if (sizeSt < 1)
			 {
				 std::wcout << L"Склад пуст\n";
			 }
			 Err();
		 }
	 }
 }

 void AddNewProduct()
 {
	 std::wstring chooseName, chooseCount,choosePrice, choose;
	 size_t count = 0;
	 double price = 0;

	 while (true)
	 {
		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			 Getline(chooseName);
			 if (chooseName == L"exit" || chooseName == L"Exit")
			 {
				 std::wcout << L"Отмена создания нового товара\n\n";
				 Sleep(1500);
				 return;
			 }
			 if (chooseName.size() < 3 || chooseName.size() > 40)
			 {
				 std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
				 Sleep(1500);
				 continue;
			 }

			 if (!isNotSameName(chooseName, nameArr, sizeSt))
			 {
				 continue;
			 }
			 else
			 {
				 break;
			 }

		 }

		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Введите кол-во нового товара или \"exit\" для выхода: ";
			 Getline(chooseCount);
			 if (chooseCount == L"exit" || chooseCount == L"Exit")
			 {
				 std::wcout << L"Отмена создания нового товара\n\n";
				 Sleep(1500);
				 return;
			 }

			 if (isNumber(chooseCount))
			 {
				 count = std::stoull(chooseCount);
				 if (count > maxStorageSize - currentStorageSize || count < 0)
				 {
					 std::wcout << L"Некорректное кол-во! На складе осталось "
						 << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
					 Sleep(2000);
				 }
				 else
				 {
					 break;
				 }
			 }

			 
		 }

		 while (true)
		 {
			 
				 system("cls");

				 std::wcout << L"Введите цену нового товара или \"exit\" для выхода: ";
				 Getline(choosePrice);
				 if (choosePrice == L"exit" || choosePrice == L"Exit")
				 {
					 std::wcout << L"Отмена создания нового товара\n\n";
					 Sleep(1500);
					 return;
				 }

				 if (isNumber(choosePrice))
				 {
					 price = std::stod(choosePrice);
					 if (price < 0 || price > maxPrice)
					 {
						 std::wcout << L"Некорректная цена! Максимально возмжная цена: "
							 << maxPrice << L" рублей\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 break;
					 }
				 }


			 
		 }

		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Новый товар: " << chooseName << L"\n";
			 std::wcout << L"Кол-во: " << count << L"\n";
			 std::wcout << L"Цена: " << price << L"\n\n";
			 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
			 Getline(choose);

			 if (choose == L"1")
			 {
				 std::wcout << L"Расширение склада";
				 for (size_t i = 0; i < 5; i++)
				 {
					 Sleep(500);
					 std::wcout << L".";
				 }
				 Sleep(500);
				 ArrPushBack(idArr, sizeSt);
				 ArrPushBack(nameArr, sizeSt);
				 ArrPushBack(countArr, sizeSt);
				 ArrPushBack(priceArr, sizeSt);
				 sizeSt++;
				 idArr[sizeSt - 1] = sizeSt;
				 nameArr[sizeSt - 1] = chooseName;
				 countArr[sizeSt - 1] = count;
				 priceArr[sizeSt - 1] = price;
				 currentStorageSize += count;
				 std::wcout << L"\n\nТовар успешно добавлен\n";
				 Sleep(1600);
				 break;
				 
		
			 }
			 else if (choose == L"2")
			 {
				 std::wcout << L"Отмена\n";
				 Sleep(1500);
				 break;
			 }
			 else
			 {
				 Err();
			 }
		 }

		 

	 }
 }

 void ChangeProductName()
 {
	 std::wstring chooseId, chooseName, choose;
	 int id = 0;
	 while (true)
	 {
		 ShowStorage(4);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции изменения названия товара\n\n";
			 return;
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
				 std::wcout << L"Введите новое название для товара: ";
				 Getline(chooseName);
				 if (chooseName == L"exit" || chooseName == L"Exit")
				 {
					 std::wcout << L"Отмена создания нового товара\n\n";
					 Sleep(1500);
					 return;
				 }
				 if (chooseName.size() < 3 || chooseName.size() > 40)
				 {
					 std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
					 Sleep(1500);
					 continue;
				 }
				 if (!isNotSameName(chooseName, nameArr, sizeSt))
				 {
					 continue;
				 }
				 else
				 {
					 while (true)
					 {
						 system("cls");
						 std::wcout << nameArr[id] << L"----->" << chooseName << L"\n\n";

						 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
						 Getline(choose);

						 if (choose == L"1")
						 {
							 std::wcout << L"Успешное изменение названия товара\n\n";
							 nameArr[id] = chooseName;
							 Sleep(1500);
							 break;
						 }
						 else if (choose == L"2")
						 {
							 std::wcout << L"Отмена изменения названия " << nameArr[id] << L"\n";
							 Sleep(1500);
							 break;
						 }
						 else
						 {
							 Err();
						 }
					 }
				 }
			 }
		 }
	 }
	
 }
 void DeleteProduct()
 {
	 std::wstring chooseId,pass;
	 int id = 0;
	 while (true)
	 {

		 ShowStorage(5);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции удаления товара\n\n";
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
				 
				 std::wcout << L"Подтвердите удаление товара: " << nameArr[id] << L"\nПароль Супер Админа: ";
				 Getline(pass);
				 if (pass == passArr[0])
				 {
					 std::wcout << L"Удаление товара";
					 for (size_t i = 0; i < 5; i++)
					 {
						 Sleep(500);
						 std::wcout << L".";
					 }
					 Sleep(500);
					 ArrDeleteByIndex(idArr, sizeSt, id);
					 ArrDeleteByIndex(nameArr, sizeSt, id);
					 currentStorageSize -= countArr[id];
					 ArrDeleteByIndex(countArr, sizeSt, id);
					 ArrDeleteByIndex(priceArr, sizeSt, id);
					 sizeSt--;

					 for (size_t i = id; i < sizeSt; i++)
					 {
						 idArr[i] = i + 1;
					 }
					 // :)
					 std::wcout << L"\n\nТовар успешно удален\n";
					 Sleep(1500);
					 if (sizeSt < 1)
					 {
						 std::wcout << L"Склад пуст!\n\n";
						 system("pause");
						 return;
					 }
					 continue;
				 }
				 else
				 {
					 Err();
				 }

			 }
		 }



	 }
 }

 void ChangeStorageLimits()
 {
	 std::wcout << "В процессе разработки";
	 Sleep(1500);
 }
