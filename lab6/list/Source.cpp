#include <iostream>
#include <Windows.h>
#include <fstream>
#include "List.h"

using namespace std;

int openMenu();
string addStr();
int getNString();
void replace(List& a);
void outputFile(List& a);
void insertItem(List& a);
void getData(List& a);

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	bool menu = true;
	List strings;

	getData(strings);

	while (menu) {
		switch (openMenu())
		{
		case 1:
			cin >> strings;
			break;
		case 2:
			strings.pop();
			break;
		case 3:
			cout << strings[getNString()] << endl;
			break;
		case 4:
			cout << "Список: ";
			cout << strings << endl;
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

	system("pause");
	return 0;
}

void getData(List& a) {
	ifstream in("words.txt", ios::binary | ios::beg);

	try
	{
		if (!in) throw "Error";
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	in >> a;
}

void insertItem(List& a) {
	string str;
	int i;

	cout << "Введите номер, в который хотите вставить строку:";
	cin >> i;

	while (cin.fail() || i>=a.getSize() || i<0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "Данные введены некорректно" << endl;
		cout << "Введите номер, в который хотите вставить строку:";
		cin >> i;
	}

	cout << "Введите строку: ";
	cin >> str;

	a.insert(str, i);
}

void outputFile(List& a) {
	ofstream file;
	string str;

	cout << "Введите имя файла: ";
	cin >> str;

	file.open(str + ".txt");

	try
	{
		if (!file) {
			throw exception::exception("Error");
		}
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	file << a;

	cout << "Успешно выведено в файл" << endl;
}

void replace(List& a) {
	string first;
	string second;

	cout << "Введите строку, которую хотите заменить: ";
	cin >> first;

	cout << "Введите строку, на которую хотите заменить: ";
	cin >> second;

	a.replace(first, second);
}

int getNString() {
	int i;
	cout << "Введите номер" << endl;
	cin >> i;

	while (cin.fail() || i<0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "Данные введены некорректно" << endl;
		cout << "Введите номер" << endl;
		cin >> i;
	}

	return i;
}

string addStr() {
	string str;
	cout << "Введите строку" << endl;
	cin >> str;

	return str;
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