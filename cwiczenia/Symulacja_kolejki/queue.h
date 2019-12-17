#pragma once
#include "customer.h"
typedef Customer Item;

class Queue
{
private:
	struct Node {
		Customer item;
		Node* next;
	};
	enum{ Q_SIZE = 10};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q);
	Queue& operator=(const Queue&) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Customer& item);
	bool dequeue( Customer& item);

};

