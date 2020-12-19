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



	 file << setw(fieldLength) << "ФАМИЛИЯ" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Имя" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Отчество" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Адресс" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Диагноз" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "№МЕД.КАРТЫ" << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;

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
	cout << "Данные выведены в файл" << endl;
}

void showInfo(Patient arr[], int length) {
	const int fieldLength = 15;

	cout << length << endl;

	printSeparator();

	cout << setw(fieldLength) << "ФАМИЛИЯ" << setw(1) << "|"<< setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Имя" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Отчество" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Адресс" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "Диагноз" << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << "№МЕД.КАРТЫ" << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;

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

	cout << "Меню" << endl;
	cout << "1. Вывести список пациентов, имеющих данный диагноз" << endl;
	cout << "2. Вывести список пациентов, номер медицинской карты которых находится в заданном интервале" << endl;
	cout << "3. Вывести полный список пациентов" << endl;
	cout << "4. Вывести данные в файл" << endl;
	cout << "5. Очистить консоль" << endl;
	cout << "0. Выход" << endl;

	cout << "Выберите нужную цифру:";

	cin >> num;

	while (cin.fail() || num < 0 || num > 5) {
		cin.clear();
		cin.ignore(32726, '\n');

		cout << "Неверно указана цифра" << endl;
		cout << "Выберите нужную цифру:";

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

	cout << "Введите диагноз:";
	cin >> diagnosis;

	for (int i = 0; i < length; i++)
	{
		if (arr[i].getDiagnosis() == diagnosis) {
			if (!find) {
				cout << "Пациенты с диагнозом: " << diagnosis << endl;
				find = true;
				showInfo(arr);
			}
			arr[i].show();
			file << arr[i];
		}
	}

	if (!find) {
		cout << "Нет пациентов с таким диагнозам" << endl;
		file << "Не удалось найти пациентов с заданным интервалом карты" << endl;

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

	cout << "Введите интервал" << endl;
	cout << "От: ";
	cin >> from;

	while (cin.fail() || from < 0) {
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "Введите корректные данные(число >= 0)" << endl;
		cout << "Введите интервал" << endl;
		cout << "От: ";
		cin >> from;
	}

	cout << "До: ";
	cin >> before;

	while (cin.fail() || from < 0 || before <= from) {
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "Введите корректные данные(число >= 0 и > до)" << endl;
		cout << "Введите интервал" << endl;
		cout << "До: ";
		cin >> before;
	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i].getMedicalCardNum() > from && arr[i].getMedicalCardNum() < before) {
			if (!find) {
				cout << "Пациенты с данным интервалом карты: от " << from << " до " << before << endl;
				showInfo(arr);
				find = true;
			}
			arr[i].show();
			file << arr[i];
		}
	}

	
	if (!find) {
		cout << "Не удалось найти пациентов с заданным интервалом карты" << endl;
		file << "Не удалось найти пациентов с заданным интервалом карты" << endl;
		return;
	}

	file.close();
	cout << setw(0);
	printSeparator();
}
