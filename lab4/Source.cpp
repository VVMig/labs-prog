#include <iostream>
#include <Windows.h>
#include <fstream>
#include "List.h"

using namespace std;

int openMenu();

template <typename T>
T addStr(T);
int getNString();

template <typename T>
void replace(List<T>& a);
template <typename T>
void outputFile(List<T>& a);
template <typename T>
void insertItem(List<T>& a);
void listForInt();
void listForFloat();
void listForStrings();

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int select;
	cout << "1. Целые числа" << endl
		 << "2. Действительные числа" << endl
		 << "3. Строки" << endl;
	cin >> select;

	while (cin.fail() || select < 1 || select > 3) {
		cout << "Введите нужную цифру" << endl;
		cout << "1. Целые числа" << endl
			<< "2. Действительные числа" << endl
			<< "3. Строки" << endl;
		cin >> select;
	}

	switch (select)
	{
	case 1:
		listForInt();
		break;
	case 2:
		listForFloat();
		break;
	case 3:
		listForStrings();
		break;
	}

	system("pause");
	return 0;
}

void listForFloat() {
	bool menu = true;
	List<double> strings;
	float a = 0;

	while (menu) {
		switch (openMenu())
		{
		case 1:
			strings.push(addStr(a));
			break;
		case 2:
			strings.pop();
			break;
		case 3:
			cout << strings[getNString()] << endl;
			break;
		case 4:
			cout << "Список: ";
			strings.show();
			break;
		case 5:
			replace(strings);
			break;
		case 6:
			strings.clear();
			break;
		case 7:
			cout << "Размер: " << strings.getSize() << endl;
			break;
		case 8:
			outputFile(strings);
			break;
		case 9:
			insertItem(strings);
			break;
		case 10:
			strings.remove(getNString());
			break;
		case 11:
			cout << strings.front() << endl;
			break;
		case 12:
			cout << strings.back() << endl;
			break;
		case 13:
			system("cls");
			break;
		default:
			menu = false;
			break;
		}
	}
}

template<typename T>
void insertItem(List<T>& a) {
	T str;
	int i;

	cout << "Введите номер, в который хотите вставить элемент:";
	cin >> i;

	while (cin.fail() || i >= a.getSize() || i < 0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "Данные введены некорректно" << endl;
		cout << "Введите номер, в который хотите вставить элемент:";
		cin >> i;
	}

	cout << "Введите элемент: ";
	cin >> str;

	a.insert(str, i);
}

template<typename T>
void outputFile(List<T>& a) {
	ofstream file;
	string str;

	cout << "Введите имя файла: ";
	cin >> str;

	file.open(str + ".txt");

	if (!file) {
		cout << "Не удалось открыть файл!!!" << endl;
		return;
	}

	for (int i = 0; i < a.getSize(); i++)
	{
		file << a[i];
		i != a.getSize() - 1 ? file << "->" : file << "\n";
	}

	cout << "Успешно выведено в файл" << endl;
}

template<typename T>
void replace(List<T>& a) {
	T first;
	T second;

	cout << "Введите элемент, которую хотите заменить: ";
	cin >> first;

	cout << "Введите элемент, на которую хотите заменить: ";
	cin >> second;

	a.replace(first, second);
}

int getNString() {
	int i;
	cout << "Введите номер" << endl;
	cin >> i;

	while (cin.fail() || i < 0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "Данные введены некорректно" << endl;
		cout << "Введите номер" << endl;
		cin >> i;
	}

	return i;
}

template<typename T>
T addStr(T str) {
	cout << "Введите новый элемент" << endl;
	cin >> str;

	return str;
}

void listForStrings() {
	bool menu = true;
	List<string> strings;
	string a = "";

	while (menu) {
		switch (openMenu())
		{
		case 1:
			strings.push(addStr(a));
			break;
		case 2:
			strings.pop();
			break;
		case 3:
			cout << strings[getNString()] << endl;
			break;
		case 4:
			cout << "Список: ";
			strings.show();
			break;
		case 5:
			replace(strings);
			break;
		case 6:
			strings.clear();
			break;
		case 7:
			cout << "Размер: " << strings.getSize() << endl;
			break;
		case 8:
			outputFile(strings);
			break;
		case 9:
			insertItem(strings);
			break;
		case 10:
			strings.remove(getNString());
			break;
		case 11:
			cout << strings.front() << endl;
			break;
		case 12:
			cout << strings.back() << endl;
			break;
		case 13:
			system("cls");
			break;
		default:
			menu = false;
			break;
		}
	}
}

void listForInt() {
	bool menu = true;
	List<int> strings;
	int a = 0;

	while (menu) {
		switch (openMenu())
		{
		case 1:
			strings.push(addStr(a));
			break;
		case 2:
			strings.pop();
			break;
		case 3:
			cout << strings[getNString()] << endl;
			break;
		case 4:
			cout << "Список: ";
			strings.show();
			break;
		case 5:
			replace(strings);
			break;
		case 6:
			strings.clear();
			break;
		case 7:
			cout << "Размер: " << strings.getSize() << endl;
			break;
		case 8:
			outputFile(strings);
			break;
		case 9:
			insertItem(strings);
			break;
		case 10:
			strings.remove(getNString());
			break;
		case 11:
			cout << strings.front() << endl;
			break;
		case 12:
			cout << strings.back() << endl;
			break;
		case 13:
			system("cls");
			break;
		default:
			menu = false;
			break;
		}
	}
}

int openMenu() {
	cout << "Меню" << endl;
	cout << "1. Добавить элемент" << endl;
	cout << "2. Удалить последний элемент" << endl;
	cout << "3. Вывести n-ю элемент" << endl;
	cout << "4. Вывести список" << endl;
	cout << "5. Поменять некоторый элемент на заданный" << endl;
	cout << "6. Очистить список" << endl;
	cout << "7. Размер списка" << endl;
	cout << "8. Вывести в файл" << endl;
	cout << "9. Вставить в заданную позицию" << endl;
	cout << "10. Удалить n-й элемент" << endl;
	cout << "11. Вывести первый элемент" << endl;
	cout << "12. Вывести последний элемент" << endl;
	cout << "13. Очистить консоль" << endl;
	cout << "0. Выход" << endl;

	int n;

	cout << "Введите нужную вам цифру" << endl;
	cin >> n;

	while (cin.fail() || n < 0 || n>13) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "Данные введены некорректно" << endl;
		cout << "Введите нужную вам цифру" << endl;
		cin >> n;
	}

	return n;
}