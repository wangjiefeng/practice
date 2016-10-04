#ifndef _JFSTRING_
#define _JFSTRING_
#include <iostream>
using std::ostream;
using std::istream;

class jfstring {
private:
	char *str;
	int len;
	static int number;
	static const int CINLIMIT = 80;
public:
	jfstring();
	jfstring(const char *s);
	jfstring(const jfstring &s);
	~jfstring();
	int length() const;
	int empty();
	jfstring & operator=(const jfstring & st);
	jfstring & operator=(const char* st);
	jfstring operator+(const char* st);
	jfstring operator+(const jfstring &st);
	friend bool operator<(const jfstring &st1, const jfstring &st2);
	friend bool operator>(const jfstring &st1, const jfstring &st2);
	friend bool operator==(const jfstring &st1, const jfstring &st2);
	friend istream& operator>>(istream &is, jfstring &st1);
	friend ostream& operator<<(ostream &os, jfstring &st1);
	char & operator[](int i);
	const char & operator[](int i) const;
};

#endif
