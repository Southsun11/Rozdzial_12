#pragma once
typedef unsigned int Item;
class Stock
{
private:
	enum { MAX = 100 };
	Item* pitems;
	int size;
	int top;
public:
	Stock(int n = MAX);
	Stock(const Stock& st);
	~Stock();
	bool isempty();
	bool isfull();
	bool push(const Item& item);
	bool pop(Item & item);
	Stock& operator=(const Stock& s);
};

