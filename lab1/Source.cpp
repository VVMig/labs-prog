#include <iostream>
#include <string>
#include "Patient.h"
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

void getListDiagnosis(Patient arr[], int length);
void getListMedicalCardRange(Patient arr[], int length);
int openMenu();
void showInfo(Patient arr[], int length = 0);
void fileOutput(Patient arr[], int length);
void printSeparator();
Patient* getDataFile(int &length);

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	Patient *patients;
	int length = 0;
	bool menu = true;
	
	patients = getDataFile(length);

	while (menu) {
		switch (openMenu())
		{
		case 1: 
			getListDiagnosis(patients, length);
			break;
		case 2:
			getListMedicalCardRange(patients, length);
			break;
		case 3:
			showInfo(patients, length);
			break;
		case 4:
			fileOutput(patients, length);
			break;
		case 5:
			system("cls");
			break;
		default:
			menu = false;
		}
	}

	delete[] patients;

	return 0;
}

Patient* getDataFile(int& length) {

	Patient* arr;
	ifstream file("patients.txt");

	try
	{
		if (!file) {
			throw "Error";
		}
	}
	catch (const std::exception&a)
	{
		cout << a.what() << endl;
	}

	string a;

	for (; !file.eof(); length++)
	{
		file >> a;
	}

	length--;
	length /= 6;
	
	arr = new Patient[length];

	try
	{
		if (!arr) throw exception::exception("Error with memory");
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	file.close();
	file.open("patients.txt");

	try {
		if(!file)
			throw "Error";
	}
	catch (const std::exception& a)
	{
		cout << a.what() << endl;
	}

	for (int i = 0; i < length; i++)
	{
		file >> arr[i];
	}

	file.close();

	return arr;
}

void printSeparator() {
	for (int i = 0; i < 96; i++) {
		cout << "=";
	}

	cout << endl;
}

void fileOutput(Patient arr[], int length) {
	if (length < 1) {
		return;
	}

	ofstream file;
	const int fieldLength = 15;
	

	file.open("output.txt", ios::app);

	try
	{
		if (!file) {
			throw exception::exception("Error with file!");
		}
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}



	 file << setw(fieldLength) << "�������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "���" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "��������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "�������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "����.�����" << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;

	 file << setw(0);

	 for (int i = 0; i < 96; i++) {
		 file << "-";
	 }

	 file << endl;

	 for (int i = 0; i < length; i++)
	 {
		 file << arr[i];
	 }

	file << setw(0);

	for (int i = 0; i < 96; i++) {
		file << "=";
	}

	file << endl;
	file.close();
	cout << "������ �������� � ����" << endl;
}

void showInfo(Patient arr[], int length) {
	const int fieldLength = 15;

	cout << length << endl;

	printSeparator();

	cout << setw(fieldLength) << "�������" << setw(1) << "|"<< setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "���" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "��������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "�������" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "����.�����" << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;

	cout << setw(0);


	for (int i = 0; i < 96; i++) {
		cout << "-";
	}

	cout << endl;

	if (!length) return;

	for (int i = 0; i < length; i++)
	{
		cout << arr[i];
	}
	
	cout << setw(0);

	printSeparator();
}

int openMenu() {
	int num;

	cout << "����" << endl;
	cout << "1. ������� ������ ���������, ������� ������ �������" << endl;
	cout << "2. ������� ������ ���������, ����� ����������� ����� ������� ��������� � �������� ���������" << endl;
	cout << "3. ������� ������ ������ ���������" << endl;
	cout << "4. ������� ������ � ����" << endl;
	cout << "5. �������� �������" << endl;
	cout << "0. �����" << endl;

	cout << "�������� ������ �����:";

	cin >> num;

	while (cin.fail() || num < 0 || num > 5) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "������� ������� �����" << endl;
		cout << "�������� ������ �����:";

		cin >> num;
	}

	return num;
}

void getListDiagnosis(Patient arr[], int length) {
	if (length < 1) {
		return;
	}

	ofstream file("output.txt", ios::app);
	string diagnosis;
	bool find = false;

	try
	{
		if (!file) throw exception("Error file");
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	cout << "������� �������:";
	cin >> diagnosis;

	for (int i = 0; i < length; i++)
	{
		if (arr[i].getDiagnosis() == diagnosis) {
			if (!find) {
				cout << "�������� � ���������: " << diagnosis << endl;
				find = true;
				showInfo(arr);
			}
			arr[i].show();
			file << arr[i];
		}
	}

	if (!find) {
		cout << "��� ��������� � ����� ���������" << endl;
		file << "�� ������� ����� ��������� � �������� ���������� �����" << endl;

		return;
	}

	file.close();
	cout << setw(0);
	printSeparator();
}

void getListMedicalCardRange(Patient arr[], int length) {
	ofstream file("output.txt", ios::app);

	try
	{
		if (!file) throw exception("Error file");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	if (length < 1) {
		return;
	}

	int from, before;
	bool find = false;

	cout << "������� ��������" << endl;
	cout << "��: ";
	cin >> from;

	while (cin.fail() || from < 0) {
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "������� ���������� ������(����� >= 0)" << endl;
		cout << "������� ��������" << endl;
		cout << "��: ";
		cin >> from;
	}

	cout << "��: ";
	cin >> before;

	while (cin.fail() || from < 0 || before <= from) {
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "������� ���������� ������(����� >= 0 � > ��)" << endl;
		cout << "������� ��������" << endl;
		cout << "��: ";
		cin >> before;
	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i].getMedicalCardNum() > from && arr[i].getMedicalCardNum() < before) {
			if (!find) {
				cout << "�������� � ������ ���������� �����: �� " << from << " �� " << before << endl;
				showInfo(arr);
				find = true;
			}
			arr[i].show();
			file << arr[i];
		}
	}

	
	if (!find) {
		cout << "�� ������� ����� ��������� � �������� ���������� �����" << endl;
		file << "�� ������� ����� ��������� � �������� ���������� �����" << endl;
		return;
	}

	file.close();
	cout << setw(0);
	printSeparator();
}
