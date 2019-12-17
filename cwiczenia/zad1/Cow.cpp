#include "Cow.h"
#include <cstring>
#include <iostream>
Cow::Cow()
{
	std::cout << "Konstruktor domyslny \n";
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}
Cow::Cow(const char* nm, const char* ho, double wt)
{
	std::cout << "Konstruktor sparametryzowany \n";
	strncpy_s(name, 20, nm, 20);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strncpy_s(hobby,len+1, ho, len + 1);
	weight = wt;
}
Cow::Cow(const Cow& c)
{
	std::cout << "Konstruktor kopiujacy \n";
	strncpy_s(this->name, 20, c.name, 20);
	int len = strlen(c.hobby);
	this->hobby = new char[len + 1];
	strncpy_s(this->hobby, len + 1, c.hobby, len + 1);
	this->weight = c.weight;
}
Cow:: ~Cow()
{
	std::cout << "Destruktor" << std::endl;
	delete [] hobby;
	
}
Cow& Cow::operator=(const Cow& c)
{
	std::cout << "Operator przypisania  \n";
	if (this == &c)
		return *this;
	int len = strlen(c.hobby);
	this->hobby = new char[len + 1];
	strncpy_s(this->name, 20, c.name, 20);
	strncpy_s(this->hobby, len + 1, c.hobby, len + 1);
	this->weight = weight;

}
void Cow::show()const
{
	std::cout << (void*)name << " " << name << std::endl;;
	std::cout << (void*)hobby << " " << hobby << std::endl;
	std::cout << &weight << " " << weight << std::endl;
	//std::cout << (void*)&weight << " " << weight << std::endl;
}