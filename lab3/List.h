#pragma once
#include <iostream>
#include <string>

using namespace std;

class List
{
	struct node {
		node(){}
		node(string str) :str(str){}

		string str;
		node* next = 0;
	};
	int size;
	node* head = 0;
public:
	List();
	List(string str);
	void insert(string t, int pos);
	void push(string t);
	void pop();
	void clear();
	void replace(string curString, string newString);
	void show();
	int getSize();
	void remove(int i);
	string front();
	string back();
	bool empty();
	string operator[](int i);
	friend ofstream& operator<<(ofstream& out, List& a);
	friend ifstream& operator>>(ifstream& in, List& a);
	friend ostream& operator<<(ostream& out, List& a);
	friend istream& operator>>(istream& in, List& a);

	~List();
};

