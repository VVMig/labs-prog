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
	cout << "1. ����� �����" << endl
		 << "2. �������������� �����" << endl
		 << "3. ������" << endl;
	cin >> select;

	while (cin.fail() || select < 1 || select > 3) {
		cout << "������� ������ �����" << endl;
		cout << "1. ����� �����" << endl
			<< "2. �������������� �����" << endl
			<< "3. ������" << endl;
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
			cout << "������: ";
			strings.show();
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
}

template<typename T>
void insertItem(List<T>& a) {
	T str;
	int i;

	cout << "������� �����, � ������� ������ �������� �������:";
	cin >> i;

	while (cin.fail() || i >= a.getSize() || i < 0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "������ ������� �����������" << endl;
		cout << "������� �����, � ������� ������ �������� �������:";
		cin >> i;
	}

	cout << "������� �������: ";
	cin >> str;

	a.insert(str, i);
}

template<typename T>
void outputFile(List<T>& a) {
	ofstream file;
	string str;

	cout << "������� ��� �����: ";
	cin >> str;

	file.open(str + ".txt");

	if (!file) {
		cout << "�� ������� ������� ����!!!" << endl;
		return;
	}

	for (int i = 0; i < a.getSize(); i++)
	{
		file << a[i];
		i != a.getSize() - 1 ? file << "->" : file << "\n";
	}

	cout << "������� �������� � ����" << endl;
}

template<typename T>
void replace(List<T>& a) {
	T first;
	T second;

	cout << "������� �������, ������� ������ ��������: ";
	cin >> first;

	cout << "������� �������, �� ������� ������ ��������: ";
	cin >> second;

	a.replace(first, second);
}

int getNString() {
	int i;
	cout << "������� �����" << endl;
	cin >> i;

	while (cin.fail() || i < 0) {
		cin.clear();
		cin.ignore(1600, '\n');

		cout << "������ ������� �����������" << endl;
		cout << "������� �����" << endl;
		cin >> i;
	}

	return i;
}

template<typename T>
T addStr(T str) {
	cout << "������� ����� �������" << endl;
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
			cout << "������: ";
			strings.show();
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
			cout << "������: ";
			strings.show();
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