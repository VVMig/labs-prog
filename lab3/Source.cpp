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
			cout << "������: ";
			cout << strings << endl;
			break;
		case 5:
			replace(strings);
			break;
		case 6:
			strings.clear();
			break;
		case 7:
			cout << "������: " << strings.getSize() << endl;
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

	cout << "������� �����, � ������� ������ �������� ������:";
	cin >> i;

	while (cin.fail() || i>=a.getSize() || i<0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "������ ������� �����������" << endl;
		cout << "������� �����, � ������� ������ �������� ������:";
		cin >> i;
	}

	cout << "������� ������: ";
	cin >> str;

	a.insert(str, i);
}

void outputFile(List& a) {
	ofstream file;
	string str;

	cout << "������� ��� �����: ";
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

	cout << "������� �������� � ����" << endl;
}

void replace(List& a) {
	string first;
	string second;

	cout << "������� ������, ������� ������ ��������: ";
	cin >> first;

	cout << "������� ������, �� ������� ������ ��������: ";
	cin >> second;

	a.replace(first, second);
}

int getNString() {
	int i;
	cout << "������� �����" << endl;
	cin >> i;

	while (cin.fail() || i<0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "������ ������� �����������" << endl;
		cout << "������� �����" << endl;
		cin >> i;
	}

	return i;
}

string addStr() {
	string str;
	cout << "������� ������" << endl;
	cin >> str;

	return str;
}

int openMenu() {
	cout << "����" << endl;
	cout << "1. �������� �������" << endl;
	cout << "2. ������� ��������� �������" << endl;
	cout << "3. ������� n-� �������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. �������� ��������� ������� �� ��������" << endl;
	cout << "6. �������� ������" << endl;
	cout << "7. ������ ������" << endl;
	cout << "8. ������� � ����" << endl;
	cout << "9. �������� � �������� �������" << endl;
	cout << "10. ������� n-� �������" << endl;
	cout << "11. ������� ������ �������" << endl;
	cout << "12. ������� ��������� �������" << endl;
	cout << "13. �������� �������" << endl;
	cout << "0. �����" << endl;

	int n;
	
	cout << "������� ������ ��� �����" << endl;
	cin >> n;

	while (cin.fail() || n < 0 || n>13) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "������ ������� �����������" << endl;
		cout << "������� ������ ��� �����" << endl;
		cin >> n;
	}

	return n;
}