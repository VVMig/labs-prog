#include "BitString.h"

char* reverse(const char* a) {
	char* tmp;
	tmp = new char[strlen(a) + 1];

	for (int i = strlen(a) - 1, j = 0; a[i]; i--, j++)
	{
		tmp[j] = a[i];
	}

	tmp[strlen(a)] = '\0';

	return tmp;
}

void BitString::addElement(const char* a) {
	BitString tmp, oth(reverse(a));

	for (int i = n - 1; i >= 0; i--)
	{
		str[i] = str[i] == oth.str[i] && str[i] == '1' ? '1' : '0';
	}
}