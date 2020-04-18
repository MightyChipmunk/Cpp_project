#include "BankingCommonDecl.h"
#include "StringClass.h"

String::String() {
	len = 0;
	str = NULL;
}

String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy_s(str, len, s);
}

String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
}

String& String::operator+=(const String& s) {
	len = len + s.len;
	char* tmp = new char[len];
	strcpy_s(tmp, len, str);
	strcat_s(tmp, len, s.str);

	if (str != NULL) 
		delete[] str;
	
	str = tmp;
	return *this;
}

String& String::operator=(const String& s) {
	if (str != NULL)
		delete[] str;

	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
	return *this;
}

bool String::operator==(const String& s) {
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s) {
	len = len + s.len;
	char* tmp = new char[len];
	strcpy_s(tmp, len, str);
	strcat_s(tmp, len, s.str);

	String tmpstr(tmp);
	delete[] tmp;
	return tmpstr;
}

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator >> (istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

String::~String() {
	if(str != NULL) 
		delete[] str;
}