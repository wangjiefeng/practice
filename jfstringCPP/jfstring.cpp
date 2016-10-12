#include "jfstring.h"
#include <cstring>
#include <cassert>
using std::cin;
using std::cout;

int jfstring::number = 0;

int jfstring::empty()
{
	return (len == 0) ? 1 : 0;
}

int jfstring::length() const
{
	return len;
}

jfstring::jfstring():
	len(1)
{
	str = new char[1];
	*str = '\0';
}

jfstring::jfstring(const char* s)
{
	number++;
	if (!s)
	{
		str = new char[1];
		*str = '\0';
	}
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

jfstring::jfstring(const jfstring &s)
{
	number++;
	if (!s.str)
	{
		str = new char[1];
		*str = '\0';
	}
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

jfstring::~jfstring()
{
	--number;
	delete[] str;
}

jfstring & jfstring::operator=(const jfstring & st)
{
	if (*this == st)
		return *this;
	delete[] str;
	len = st.len + 1;
	str = new char[len];
	return *this;
}

jfstring & jfstring::operator=(const char* st)
{
	delete[] str;
	len = strlen(st);
	str = new char[len+1];
	strcpy(str, st);
	return *this;
}

jfstring jfstring::operator+(const char* st)
{
	if (!st)
		return *this;
	len += strlen(st);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, st);
	return  *this;
}

jfstring jfstring::operator+(const jfstring &st)
{
	if (!st.len)
		return *this;
	len += st.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, st.str);
	return  *this;
}

char & jfstring::operator[](int i)
{
	assert(i < len);
	return str[i];
}

const char & jfstring::operator[](int i) const
{
	assert(i < len);
	return str[i];
}

bool operator<(const jfstring &st1, const jfstring &st2)
{
	return (strcmp(st1.str, st2.str));
}

bool operator>(const jfstring &st1, const jfstring &st2)
{
	return st1 < st2;
}

bool operator==(const jfstring &st1, const jfstring &st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

istream& operator>>(istream &is, jfstring &st)
{
	char temp[jfstring::CINLIMIT];
	is.get(temp, jfstring::CINLIMIT);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

ostream& operator<<(ostream &os, jfstring &st)
{
	os << st.str;
	return os;
}

