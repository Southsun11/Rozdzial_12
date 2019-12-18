#include "Stock.h"
#include <iostream>
Stock::Stock(int n)
{
	pitems = new Item[n];
	size = n;
	top = 0;
}
Stock::Stock(const Stock& st)
{
	Item * temp = this->pitems;
	this->pitems = new Item[st.size];
	this->size = st.size;
	this->top = st.top;
	for (int i = 0; i < top; i++)
		this->pitems[i] = st.pitems[i];
	delete[] temp;

}
Stock::~Stock()
{
	delete[] this->pitems;
	std::cout << "Destruktor" << std::endl;
}
bool Stock::isempty()
{
	return top == 0;
}
bool Stock::isfull()
{
	return top == size;
}
bool Stock::push(const Item& item)
{
	if (top == size)
		return false;
	else
		pitems[top++] = item;
	return true;
}
bool Stock::pop(Item & item)
{
	if (top == 0)
		return false;
	else
		item = pitems[--top];
	return true;
}
Stock& Stock::operator=(const Stock& s)
{
	if (this == &s)
		return *this;
	Item* temp = this->pitems;
	this->pitems = new Item[s.size];
	this->size = s.size;
	this->top = s.top;
	for (int i = 0; i < top; i++)
		this->pitems[i] = s.pitems[i];
	delete[] temp;
	return *this;


}