#include "Stringbad.h"
#include <cstring>
int Stringbad::num_strings = 0;
Stringbad::Stringbad()
{
	str = new char[1];
	len = 1;
	str[0] = '\0';
	num_strings++;
	std::cout << "Konstruktor domyslny" << std::endl;
}
Stringbad::Stringbad(const char* c)
{
	len = strlen(c) + 1;
	str = new char[len];
	strncpy_s(str,len,c, len);
	num_strings++;
	std::cout << "Konstruktor sparametryzowany" << std::endl;
}
Stringbad::Stringbad(const Stringbad& s)
{
	len = s.len;
	str = new char[len];
	strncpy_s(str, len, s.str, len);
	num_strings++;
	std::cout << "Konstruktor kopiujacy" << std::endl;
}
Stringbad::~Stringbad()
{
	num_strings--;
	delete[] str;
	std::cout << "Destruktor" << std::endl;
	
}
Stringbad& Stringbad::operator=(const Stringbad& s)
{
	if (this == &s)
		return *this;
	delete [] this->str;
	this->len = s.len;
	this->str = new char[len];
	strncpy_s(this->str, this->len, s.str, s.len);
	return *this;

}
Stringbad& Stringbad::operator=(const char* s)
{
	delete[] this->str;
	len = strlen(s) +1;
	str = new char[len];
	strncpy_s(this->str, this->len, s, this->len);
	return *this;
}
std::ostream& operator<< (std::ostream& os, const Stringbad& str)
{
	os << str.str;
	return os;
}

bool operator<(const Stringbad& s1, const Stringbad& s2)
{
	return (std::strcmp(s1.str, s2.str) < 0);
}

 bool operator>(const Stringbad&s1, const Stringbad&s2)
{
	 return (std::strcmp(s1.str, s2.str) > 0);
}
 bool operator==(const Stringbad&s1, const Stringbad&s2)
 {
	 return (std::strcmp(s1.str, s2.str));
}
 std::istream& operator>>(std::istream& is,  Stringbad& str)
{
	 char temp[Stringbad::CINLIM];
	 is.get(temp, Stringbad::CINLIM);
	 if (is)
		 str = temp;
	 while (is.get() != '\n')
		 continue;
	 return is;
	 
}
 char & Stringbad::operator[](int n)
{
	 return str[n];
}
 const char& Stringbad::operator[](int  i) const
 {
	 return str[i];
}
  int Stringbad::How_Many()
 {
	 return num_strings;
}