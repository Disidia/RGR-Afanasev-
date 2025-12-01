#include "menu.h"
#include <iostream>
#include <limits>

using namespace std;

void showMenu() {
	cout << "\n=== МЕНЮ ===\n"
	<< "1 - Ввести текст (ручной ввод или загрузить файл)\n"
	<< "2 - Шифровать текст (input.txt -> encoded.txt + показать в консоли)\n"
	<< "3 - Дешифровать текст (encoded.txt -> decoded.txt + показать в консоли)\n"
	<< "4 - Показать содержимое файла\n"
	<< "5 - Зарегистрировать нового пользователя\n"
	<< "0 - Выход\n"
	<< "Ваш выбор: ";
}


int chooseMethodPrompt() {
	cout << "Выберите метод:\n"
	<< "1 - последовательности нулей и единиц\n"
	<< "2 - шифр Гронсфельда\n"
	<< "3 - шифр Виженера\n"
	<< "Ваш выбор: ";
	int method;
	if (!(cin >> method)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
	}
	cin.ignore();
	return method;
}
