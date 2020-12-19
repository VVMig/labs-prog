//#include <string>
//#include "List.h"
//
//using namespace std;
//
//template<typename T>
//inline List<T>::List() :size(0) {}
//
//template<typename T>
//inline List<T>::List(T str) : head(new node(str)), size(1) {}
//
//template<typename T>
//inline void List<T>::insert(T t, int pos)
//{
//	if (pos >= size || pos < 0) return;
//
//	if (pos == size - 1) {
//		push(t);
//		return;
//	}
//
//	int i = size - 1;
//
//	node* prev = head;
//	node* newNode = new node(t);
//
//	while (i != pos) {
//		prev = prev->next;
//		i--;
//	}
//
//	newNode->next = prev->next;
//	prev->next = newNode;
//
//	size++;
//}
//
//template<typename T>
//inline void List<T>::push(T t) {
//	size++;
//
//	if (!head) {
//		head = new node(t);
//		return;
//	}
//
//	if (node* m = new node(t)) {
//		m->next = this->head;
//		head = m;
//	}
//}
//
//template<typename T>
//inline void List<T>::pop()
//{
//	if (!size) return;
//	node* cur = head;
//
//	this->head = this->head->next;
//	size--;
//
//	delete cur;
//}
//
//template<typename T>
//inline void List<T>::clear()
//{
//	while (size) {
//		pop();
//	}
//}
//
//template<typename T>
//inline void List<T>::replace(T curString, T newString) {
//	node* tmp = head;
//
//	while (tmp) {
//		if (tmp->str == curString) {
//			tmp->str = newString;
//		}
//		tmp = tmp->next;
//	}
//}
//
//template<typename T>
//inline void List<T>::show() {
//	node* tmp = head;
//
//	while (tmp) {
//		cout << tmp->str;
//		tmp->next ? cout << " <- " : cout << endl;
//		tmp = tmp->next;
//	}
//	cout << endl;
//}
//
//template<typename T>
//inline int List<T>::getSize()
//{
//	return size;
//}
//
//template<typename T>
//inline T List<T>::front()
//{
//	return head->str;
//}
//
//template<typename T>
//inline T List<T>::back()
//{
//	node* cur = head;
//	while (cur->next) {
//		cur = cur->next;
//	}
//
//	return cur->str;
//}
//
//template<typename T>
//inline bool List<T>::empty()
//{
//	return !size ? false : true;
//}
//
//template<typename T>
//inline T List<T>::operator[](int i)
//{
//	try
//	{
//		if (i < 0 || i >= size) throw;
//	}
//	catch (const std::exception& e)
//	{
//		e.~exception();
//	}
//
//	node* current = head;
//	int res = size - 1;
//
//	if (res == i) return current->str;
//
//	while (current) {
//		if (res == i) return current->str;
//		current = current->next;
//		res--;
//	}
//}
//
//template<typename T>
//inline List<T>::~List() {
//	clear();
//}
