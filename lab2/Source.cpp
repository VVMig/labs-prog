#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "String.h"

using namespace std;

String* sort(String arr[], int length);
String* addString(String arr[], int &length);
int openMenu();
void addToEndOfString(String arr[], int length);
bool compareStrings(String arr[], int length);
void outputFile(String arr[], int length);
void show(String arr[], int length);
String* getData(String a[], int& length);

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length = 0;
	bool menu = true;
	String* str = nullptr;

	str = getData(str, length);

	while (menu) {
		cout << endl;
		switch (openMenu())
		{
		case 1:
			addToEndOfString(str, length);
			break;
		case 2:
			compareStrings(str, length);
			break;
		case 3:
			sort(str, length);
			break;
		case 4:
			outputFile(str, length);
			break;
		case 5:
			str = addString(str, length);
			length += 1;
			break;
		case 6:
			show(str, length);
			break;
		case 7:
			system("cls");
			break;
		default:
			menu = false;
			break;
		}
	}

	return 0;
}

String* getData(String a[], int& length) {
	ifstream in("words.txt", ios::binary);

	try
	{
		if (!in) throw "Error";
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	char str[100];

	while (in >> str) {
		length++;
	}

	a = new String[length];

	try
	{
		if (!a) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	in.clear();
	in.seekg(0);

	for (int i = 0; i < length; i++)
	{
		in >> a[i];
	}

	return a;
}

void show(String arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout <<"["<<i+1<<"]: " <<arr[i] << endl;
	}
	cout << endl;
}

String* addString(String arr[], int &length) {
	String* newArr = new String[length + 1];

	for (int i = 0; i < length; i++)
	{
		newArr[i] = arr[i];
	}

	cout << "Введите новую строку: ";
	cin >> newArr[length];
		
	cout << "Строка успешно добавлена" << endl;
	return newArr;
}

void outputFile(String arr[], int length) {
	String a;
	ofstream file;

	cout << "Введите название файла: ";
	cin >> a;

	file.open((a + ".txt").c_str());

	try
	{
		if (!file) {
			throw "Error";
		}
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}


	for (int i = 0; i < length; i++)
	{
		file << arr[i] << ' ';
	}

	cout << "Данные выведены в файл успешно" << endl;
}

bool compareStrings(String arr[], int length) {
	int i;
	String tmpStr;

	cout << "Выберите номер строки, c которым хотите сравнить: ";
	cin >> i;

	while (cin.fail() || i < 0 || i >= length) {
		cin.clear();
		cin.ignore(32726, '\n');


		cout << "Введите корректные данные" << endl;
		cin >> i;
	}

	cout << "Введите строку: ";
	cin >> tmpStr;

	if (tmpStr == arr[i]) {
		cout << "Строки равны" << endl;
	}
	else if (tmpStr.Length < arr[i].Length) {
		cout << "Первая строка больше" << endl;
	}
	else cout << "Вторая строка больше" << endl;

	return tmpStr == arr[i];
}

void addToEndOfString(String arr[], int length) {
	int i;
	String tmpStr;
	cout << "Выберите номер строки, к которому хотите добавить строку: ";
	cin >> i;

	while (cin.fail() || i < 0 || i >= length) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "Введите корректные данные" << endl;
		cin >> i;
	}

	cout << "Введите строку: ";
	cin >> tmpStr;

	arr[i] += tmpStr;
	cout << "Строка " << i << " модифицированна" << endl;
}

String* sort(String arr[], int length) {
	String tmp;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++) {
			if (strcmp(arr[j].c_str(), arr[j + 1].c_str()) > 0) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	cout << "Массив успешно отсортирован" << endl;
	return arr;
}

int openMenu() {
	int num;

	cout << "Меню" << endl;
	cout << "1. Добавить в конец строки" << endl;
	cout << "2. Сравнить строку" << endl;
	cout << "3. Сортировать массив" << endl;
	cout << "4. Вывести массив строк в файл" << endl;
	cout << "5. Добавить строку в массив" << endl;
	cout << "6. Вывести массив" << endl;
	cout << "7. Очистить консоль" << endl;
	cout << "0. Выход" << endl;

	cout << "Выберите нужную цифру:";

	cin >> num;

	while (cin.fail() || num < 0 || num > 8) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "Неверно указана цифра" << endl;
		cout << "Выберите нужную цифру:";

		cin >> num;
	}

	return num;
}