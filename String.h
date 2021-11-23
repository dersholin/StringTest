#ifndef STRING_H_
#define STRING_H_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class String
{
private:
	char* str_data;
public:
	String(const char* cstr = 0);
	String(const String& str);
	~String();
	String& operator = (const String& str);
	char* getData() const { return str_data; }
};

inline String::String(const char* cstr)
{
	if (cstr)
	{
		str_data = new char[strlen(cstr) + 1];
		strcpy(str_data, cstr);
	}
	else
	{
		str_data = new char[1];
		*str_data = '\0';
	}
}

inline String::String(const String& str)
{
	str_data = new char[strlen(str.str_data) + 1];
	strcpy(str_data, str.str_data);
}

inline String::~String()
{
	delete[] str_data;
}

inline String& String::operator =(const String& str)
{
	if (this == &str)
		return *this;

	delete[] str_data;
	str_data = new char[strlen(str.str_data) + 1];
	strcpy(str_data, str.str_data);
	return *this;
}


std::ostream& operator <<(std::ostream& os, const String& str)
{
	os << str.getData();
	return os;
}

#endif // !STRING_H_

