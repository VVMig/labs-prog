#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string a;
	vector<string> arr;
	int n;

	try
	{
		if (argc < 3) {
			throw exception("No name of files in parametrs");
		}
		else a = argv[1];
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
		return -1;
	}

	cout << a << endl;

	ifstream in("C:\\Users\\vovam\\source\\repos\\Project4\\Project4\\"+ a + ".txt");

	try
	{
		if (!in) throw exception("File have not opened");
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
		return -1;
	}


	while (in >> a) {
		arr.push_back(a);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' '<<endl;
	}

	in.close();
	a=argv[2];

	ofstream out("C:\\Users\\vovam\\source\\repos\\Project4\\Project4\\" + a + ".txt", ios::trunc);

	try
	{
		if(!out) throw exception("File have not opened");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
		return -1;
	}

	cout << "Enter n last strings: ";
	cin >> n;

	for (size_t i = arr.size() - 1, j = 0;j < n; i--, j++)
	{
		out << arr[i] << ' ';
		if (i == 0) break;
	}

	out.close();

	return 0;
}