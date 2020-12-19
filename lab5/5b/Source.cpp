#include <iostream>
#include <ctime>
#include "TernaryVector.h"

using namespace std;

int* enterArr(TernaryVector &a);
int menu();
bool checkOrt(TernaryVector a);
TernaryVector intersection(TernaryVector a);

int main() {
	srand(time(NULL));
	bool end = true;

	TernaryVector a;

	enterArr(a);

	while (end) {
		switch (menu())
		{
		case 1:
			a.show();
			break;
		case 2:
			enterArr(a);
			break;
		case 3:
			if (checkOrt(a)) {
				cout << "Vectors are orthogonal" << endl;
			}
			else cout << "Vectors are not orthogonal" << endl;
			break;
		case 4:
			if (true) {
				int i;
				cout << "Enter i element to show: ";
				cin >> i;
				cout << a[i] << endl;
			}
			break;
		case 5:
			cout << a.getSize() << endl;
			break;
		case 6:
			intersection(a);
			break;
		case 7:
			cout<< a.undefinedComponents() <<endl;
			break;
		default:
			end = false;
			break;
		}
	}

	return 0;
}

int menu() {
	cout << "--------------------------------" << endl;

	cout << "1. Show vector" << endl
		<< "2. Fill vector" << endl
		<< "3. Check orthogonality" << endl
		<< "4. Show i element" << endl
		<< "5. Get size of vector" << endl
		<< "6. Make an intersection" << endl
		<< "7. Number of component that has value 2" << endl
		<< "0. End" << endl;

	int a;
	cout << "Enter operation: ";
	cin >> a;

	while (cin.fail() || a < 0 || a > 7) {
		cout << "Error!!!" << endl;
		cout << "Enter operation: ";
		cin >> a;
	}

	return a;
}

bool checkOrt(TernaryVector a) {
	TernaryVector b;

	cout << "Fill second vector to check orthogonality" << endl;
	enterArr(b);

	a.show();
	b.show();

	return a.ort(b);
}

TernaryVector intersection(TernaryVector a) {
	TernaryVector b;

	cout << "Fill second vector to do intersection" << endl;
	enterArr(b);

	if (a.ort(b)) {
		cout << "Vectors are orthogonal!!!" << endl;
		return a;
	}

	a.show();
	b.show();

	b = a & b;
	b.show();

	return b;
}

int* enterArr(TernaryVector &a) {
	int* arr;
	int length;
	char c;

	cout << "Enter the size of vector: ";
	cin >> length;

	while (cin.fail() || length < 1)
	{
		cout << "Enter the size of vector: ";
		cin >> length;
	}

	arr = new int[length];


	cout << "Fill with random numbers?(y or any other symbol): ";
	cin >> c;

	if (c == 'y') {
		for (int i = 0; i < length; i++)
		{
			arr[i] = rand()%100;
		}
	}
	else {
		for (int i = 0; i < length; i++)
		{
			cout << i + 1 << ": ";
			cin >> arr[i];
		}
	}

	a.setVectors(arr, length);

	return arr;
}