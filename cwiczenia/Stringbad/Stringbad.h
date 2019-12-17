#pragma once
#include <iostream>
class Stringbad
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	Stringbad();
	Stringbad(const char*);
	~Stringbad();
	Stringbad(const Stringbad&);
	Stringbad& operator=(const Stringbad&);
	Stringbad& operator=(const char*);
	Stringbad operator+( const Stringbad&) const;
	int length() { return len; }
	friend bool operator<(const Stringbad&, const Stringbad&);
	friend bool operator>(const Stringbad&, const Stringbad&);
	friend bool operator==(const Stringbad&, const Stringbad&);
	friend std::ostream& operator<< (std::ostream& os, const Stringbad& str);
	friend std::istream& operator>>(std::istream &,  Stringbad&);
	char& operator[](int n);
	const char& operator[](int  i) const;
	static int How_Many();
	void stringlow();
	void stringupper();
	int howmany(char);

};

