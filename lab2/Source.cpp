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

	cout << "������� ����� ������: ";
	cin >> newArr[length];
		
	cout << "������ ������� ���������" << endl;
	return newArr;
}

void outputFile(String arr[], int length) {
	String a;
	ofstream file;

	cout << "������� �������� �����: ";
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

	cout << "������ �������� � ���� �������" << endl;
}

bool compareStrings(String arr[], int length) {
	int i;
	String tmpStr;

	cout << "�������� ����� ������, c ������� ������ ��������: ";
	cin >> i;

	while (cin.fail() || i < 0 || i >= length) {
		cin.clear();
		cin.ignore(32726, '\n');


		cout << "������� ���������� ������" << endl;
		cin >> i;
	}

	cout << "������� ������: ";
	cin >> tmpStr;

	if (tmpStr == arr[i]) {
		cout << "������ �����" << endl;
	}
	else if (tmpStr.Length < arr[i].Length) {
		cout << "������ ������ ������" << endl;
	}
	else cout << "������ ������ ������" << endl;

	return tmpStr == arr[i];
}

void addToEndOfString(String arr[], int length) {
	int i;
	String tmpStr;
	cout << "�������� ����� ������, � �������� ������ �������� ������: ";
	cin >> i;

	while (cin.fail() || i < 0 || i >= length) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "������� ���������� ������" << endl;
		cin >> i;
	}

	cout << "������� ������: ";
	cin >> tmpStr;

	arr[i] += tmpStr;
	cout << "������ " << i << " ���������������" << endl;
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

	cout << "������ ������� ������������" << endl;
	return arr;
}

int openMenu() {
	int num;

	cout << "����" << endl;
	cout << "1. �������� � ����� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ����������� ������" << endl;
	cout << "4. ������� ������ ����� � ����" << endl;
	cout << "5. �������� ������ � ������" << endl;
	cout << "6. ������� ������" << endl;
	cout << "7. �������� �������" << endl;
	cout << "0. �����" << endl;

	cout << "�������� ������ �����:";

	cin >> num;

	while (cin.fail() || num < 0 || num > 8) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "������� ������� �����" << endl;
		cout << "�������� ������ �����:";

		cin >> num;
	}

	return num;
}