#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class List
{
	template <typename T1> friend  ostream& operator << (ostream&, const List<T1>&);
	template <typename T1> friend  istream& operator >> (istream&, const List<T1>&);

	struct node {
		node() {}
		node(T str) :str(str) {}

		T str;
		node* next = 0;
	};
	int size;
	node* head = 0;
public:
	List();
	List(T str);
	List(const List<T>& oth);
	void insert(T t, int pos);
	void push(T t);
	void pop();
	void clear();
	void show();
	void remove(int i);
	int getSize();
	T front();
	T back();
	bool empty();
	T operator[](int i);
	bool operator==(List<T>& oth) {
		if (oth.size != size) return false;
		node* currentL = head;
		node* currentR = oth.head;

		while (currentL && currentR) {
			if (currentL->str != currentR->str) return false;
			currentL = currentL->next;
			currentR = currentR->next;
		}
		return true;
	}
	bool operator!=(List<T>& oth) {
		if (oth.size != size) return true;
		node* currentL = head;
		node* currentR = oth.head;

		while (currentL && currentR) {
			if (currentL->str != currentR->str) return true;
			currentL = currentL->next;
			currentR = currentR->next;
		}
		return false;
	}
	List<T>& operator+(List<T>& oth) {
		List<T> tmp;

		node* current = head;

		while (current) {
			tmp.push(current->str);
			current = current->next;
		}

		current = oth.head;

		while (current) {
			tmp.push(current->str);
			current = current->next;
		}

		tmp.size = size + oth.size;

		return tmp;
	}
	List<T>& operator=(const List<T>& oth) {
		this->clear();
		node* current = oth.head;

		while (current) {
			this->push(current->str);
			current = current->next;
		}

		this->size = oth.size;

		return *this;
	}
	~List();
};

template<typename T>
inline List<T>::List(const List<T>& oth) {

	this->clear();

	node* current = oth.head;

	while (current) {
		this->push(current->str);
		current = current->next;
	}

	this->size = oth.size;
}

template<typename T>
inline List<T>::List() :size(0) {}

template<typename T>
inline List<T>::List(T str) : head(new node(str)), size(1) {}

template<typename T>
inline void List<T>::insert(T t, int pos)
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
		if (!newNode) throw exception("Error with memory");
	}
	catch (const std::exception& err)
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

template<typename T>
inline void List<T>::push(T t) {
	size++;

	if (!head) {
		head = new node(t);
		return;
	}

	if (node* m = new node(t)) {
		m->next = this->head;
		head = m;
	}
}

template<typename T>
inline void List<T>::pop()
{
	if (!size) return;
	node* cur = head;


	this->head = this->head->next;
	size--;

	delete cur;
}

template<typename T>
inline void List<T>::clear()
{
	while (size) {
		pop();
	}
}

template<typename T>
inline void List<T>::show() {
	node* tmp = head;

	while (tmp) {
		cout << tmp->str;
		tmp->next ? cout << " -> " : cout << endl;
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void List<T>::remove(int pos)
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

template<typename T>
inline int List<T>::getSize()
{
	return size;
}

template<typename T>
inline T List<T>::front()
{
	return head->str;
}

template<typename T>
inline T List<T>::back()
{
	node* cur = head;

	try
	{
		if (!cur) throw exception("Error with memory");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	while (cur->next) {
		cur = cur->next;
	}

	return cur->str;
}

template<typename T>
inline bool List<T>::empty()
{
	return !size ? false : true;
}

template<typename T>
inline T List<T>::operator[](int i)
{
	try
	{
		if (i < 0 || i >= size) throw;
	}
	catch (const std::exception& e)
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

template<typename T>
inline List<T>::~List() {
	clear();
}

template<typename T1>
inline ostream& operator<<(ostream& out, List<T1>& a)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		out << a[i];
		i != a.getSize() - 1 ? out << "->" : out << "\n";
	}

	return out;
}

template<typename T1>
inline istream& operator>>(istream& in, List<T1>& a)
{
	T1 tmp;
	in >> tmp;
	a.push(tmp);

	return in;
}
