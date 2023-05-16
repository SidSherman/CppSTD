/*
Дана строка слов, разделенных пробелами и запятыми.
Подсчитать количество подстрок, заключенных между запятыми.
Определить длину самого короткого слова.
*/

#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;

class String {

private:
	int _len;
	char* _str;

public:
	String()
	{
		_len = 0;
		_str = NULL;
	}

	String(const char* str)
	{
		_len = strlen(str);
		_str = new char[_len + 1];

		for (int i = 0; i < _len; i++)
		{
			_str[i] = str[i];
		}
		_str[_len] = '\0';
	}

	String(const char* str, int len)
	{
		_len = len;
		_str = new char[_len + 1];

		for (int i = 0; i < _len; i++)
		{
			_str[i] = str[i];
		}
		_str[_len] = '\0';
	}

	String(String& str)
	{

		_len = str._len;
		_str = new char[_len];
		char* tmp = str.get_str();
		for (int i = 0; i < _len; i++)
		{
			_str[i] = tmp[i];
		}
		_str[_len] = '\0';

	}

	void Clear()
	{
		_str = NULL;
		_len = 0;

	}

	int get_len()
	{
		return _len;
	}

	char* get_str()
	{
		return _str;
	}

	char * operator = (String & str) {

		_len = str._len;
		_str = new char[_len];
		char* tmp = str.get_str();
		for (int i = 0; i < _len; i++)
		{
			_str[i] = tmp[i];
		}
		_str[_len] = '\0';

		return _str;
	}


	char operator [](int index) {

		return _str[index];
	}

	~String() {
		Clear();
	}
};


int main() {

	setlocale(LC_ALL, "ru");

	String str("ABC", 4);

	String str2(str);

	for (int i = 0; i < str.get_len(); i++)
		printf("%c", str[i]);

	for (int i = 0; i < str2.get_len(); i++)
		printf("%c", str2[i]);

	String str3("123455");
	for (int i = 0; i < str3.get_len(); i++)
		printf("%c", str3[i]);

	str3 = str;


	String str4("123455");
	for (int i = 0; i < str4.get_len(); i++)
		printf("%c", str4[i]);

	for (int i = 0; i < str3.get_len(); i++)
		printf("%c", str3[i]);
	for (int i = 0; i < str3.get_len(); i++)
		printf("%c", str3[i]);

	String kek("Дана строка слов, разделенных пробелами и запятыми. \
		Подсчитать количество подстрок, заключенных между запятыми.\
		Определить длину самого короткого слова.");

	int begin = 0, end = 0;
	int k = 0;
	int count = 0;
	int lenght = kek.get_len();
	for (int i = 0; i < kek.get_len(); i++)
	{
		if ((kek[i] != ' ' && kek[i] != ',') && k == 0)
		{
			k = 1;
			begin = i;
		}


		if ((kek[i] == ' ' || kek[i] == ',' || kek[i] == '.') && k == 1)
		{
			k = 0;
			end = i;
			if (lenght > end - begin)
				lenght = end - begin;
		}

		if (kek[i] == ',')
			count++;
	}


	cout << "Количество запятых: " << count << "\n" << "Длина самого короткого слова: " << lenght;

	return 0;

}