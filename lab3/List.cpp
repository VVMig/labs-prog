#include "List.h"
#include <fstream>
#include <string>

using namespace std;

List::List():size(0){}
List::List(string str):head(new node(str)), size(1){
	try
	{
		if (!head) {
			throw exception::exception("Error with memory!!!");
		}
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

void List::insert(string t, int pos)
{
	if (pos >= size || pos < 0) return;

	if (pos == size - 1) {
		push(t);
		return;
	}

	int i = size - 1;

	node* prev = head;
	node* newNode = new node(t);

	try
	{
		if (!newNode) {
			throw exception::exception("Error with memory!!!");
		}
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	while (i != pos) {
		prev = prev->next;
		i--;
	}

	newNode->next = prev->next;
	prev->next = newNode;

	size++;
}

void List::push(string t) {
	size++;

	if (!head) {
		head = new node(t);

		try
		{
			if (!head) {
				throw exception::exception("Error with memory!!!");
			}
		}
		catch (const std::exception& err)
		{
			cout << err.what() << endl;
		}

		return;
	}

	if (node* m = new node(t)) {
		m->next = this->head;

		head = m;
	}
}

void List::pop()
{
	if (!size) return;
	node *cur = head;

	this->head = this->head->next;
	size--;

	delete cur;
}

void List::clear()
{
	while (size) {
		pop();
	}
}

void List::replace(string curString, string newString) {
	node* tmp = head;

	while (tmp) {
		if (tmp->str == curString) {
			tmp->str = newString;
		}
		tmp = tmp->next;
	}
}

void List::show() {
	node* tmp = head;
	
	while (tmp) {
		cout << tmp->str;
		tmp->next ? cout << " -> " : cout << endl;
		tmp = tmp->next;
	}
	cout << endl;
}

int List::getSize()
{
	return size;
}

void List::remove(int pos)
{
	if (pos >= size || pos < 0) return;

	if (pos == size - 1) {
		pop();
		return;
	}

	int i = size - 1;

	node* prev = head;
	node* cur = head->next;
	i--;

	while (i != pos) {
		prev = cur;
		cur = cur->next;
		i--;
	}

	prev->next = cur->next;
	delete cur;

	size--;
}

string List::front()
{
	return head->str;
}

string List::back()
{
	node* cur = head;
	while (cur->next) {
		cur = cur->next;
	}

	return cur->str;
}

bool List::empty()
{
	return !size ? false : true;
}

string List::operator[](int i)
{
	try
	{
		if (i < 0 || i >= size) throw "Error for access";
	}
	catch (const std::exception&e)
	{
		e.~exception();
	}

	node* current = head;
	int res = size - 1;

	if (res == i) return current->str;

	while (current) {
		if (res == i) return current->str;
		current = current->next;
		res--;
	}
}

ofstream& operator<<(ofstream& out, List& a) {
	for (int i = 0; i < a.getSize(); i++)
	{
		out << a[i];
		i != a.getSize() - 1 ? out << " " : out << "\n";
	}

	return out;
}
ifstream& operator>>(ifstream& in, List& a) {
	string str;

	while (in >> str) {
		a.push(str);
	}

	return in;
}

ostream& operator<<(ostream& out, List& a) {
	for (int i = 0; i < a.getSize(); i++)
	{
		out << a[i];
		i != a.getSize() - 1 ? out << " " : out << "\n";
	}

	return out;
}

istream& operator>>(istream& in, List& a) {
	string str;

	in >> str;

	a.push(str);

	return in;
}

List::~List() {
	clear();
}