#pragma once
class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() :arrive(0), processtime(0) {}
	void set(long when);
	long when() const { return arrive; }
	long ptime() const { return processtime; }
};

