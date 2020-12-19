#include <iostream>
#include "List.h"
#include <ctime>

using namespace std;

void showChar();
void showInt();
void showDouble();

int main() {
	srand(time(NULL));

	showInt();
	showChar();
	showDouble();

	return 0;
}

void showDouble() {
	cout << "Double" << endl;

	List<double> a, b; 
	int j;
	double t;

	for (int i = 0; i < 5; i++)
	{
		double tmp = (rand() % 100 + 1.);
		a.push(tmp);
		b.push(tmp);
	}

	cout << "a.push: ";
	cin >> a;

	cout << "b.push: ";
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "delete: ";
	cin >> j;

	a.remove(j);
	b.remove(j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "insert: index -  ";
	cin >> j;
	cout << "element: ";
	cin >> t;

	a.insert(t, j);
	b.insert(t, j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "a == b" << endl;
	if (a == b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a != b" << endl;
	if (a != b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a + b" << endl;
	cout << (a + b) << endl;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = b;

	cout << "a=b " << endl;

	cout << "a: " << a << endl;
}

void showInt() {
	cout << "Int" << endl;

	List<int> a, b;
	int j, t;

	for (int i = 0; i < 5; i++)
	{
		int tmp = (rand() % 100 + 1);
		a.push(tmp);
		b.push(tmp);
	}

	cout << "a.push: ";
	cin >> a;

	cout << "b.push: ";
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "delete: ";
	cin >> j;

	a.remove(j);
	b.remove(j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "insert: index -  ";
	cin >> j;
	cout << "element: ";
	cin >> t;

	a.insert(t, j);
	b.insert(t, j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "a == b" << endl;
	if (a == b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a != b" << endl;
	if (a != b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a + b" << endl;
	cout << (a + b) << endl;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = b;

	cout << "a=b: " << a << endl;
}

void showChar() {
	cout << "Char" << endl;

	List<char> a, b;
	int j;
	char t;

	for (int i = 0; i < 5; i++)
	{
		char tmp = (char)(rand() % 100 + 1);
		a.push(tmp);
		b.push(tmp);
	}

	cout << "a.push: ";
	cin >> a;

	cout << "b.push: ";
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "delete: ";
	cin >> j;

	a.remove(j);
	b.remove(j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "insert: index -  ";
	cin >> j;
	cout << "element: ";
	cin >> t;

	a.insert(t, j);
	b.insert(t, j);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "a == b" << endl;
	if (a == b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a != b" << endl;
	if (a != b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "a + b" << endl;
	cout << (a + b) << endl;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = b;

	cout << "a=b: " << a << endl;
}