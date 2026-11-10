#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;

 void CreateStorage(int mode)
 {
	 const size_t staticSize = 10;
	
	 size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	 std::wstring nameArrStatic[staticSize]
	 {
		 L"Керамбит Волны",L"Нож-Бабочка Волны",L"Штык-Нож М9 Легенды",L"Штык-Нож Легенды",L"AWP Dragon Lore",L"AWP Gungnir",L"M4 Вой",L"AK-47 Огненый змей",
		 L"Спортивные-Перчатки Ящик Пандоры",L"USP Неонуар"
	 };
	 size_t countArrStatic [staticSize];
	 double priceArrStatic [staticSize];
 }
