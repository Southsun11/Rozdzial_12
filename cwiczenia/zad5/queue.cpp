#include "queue.h"
#include <iostream>

Queue::Queue(int qs ) :qsize(qs)
{
	rear = nullptr;
	front = nullptr;
	items = 0;
}
Queue::~Queue()
{
	while (front != nullptr)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull()const
{
	return items == qsize;
}
int Queue::queuecount()const
{
	return items;
}
bool Queue::enqueue(const Customer& item)
{
	if (isfull())
	{
		return false;
	}
	Node* temp = new Node;
	temp->item = item;
	temp->next = nullptr;
	if(isempty())
		front  = temp;
	else
		rear->next = temp;
	rear = temp;
	items++;
	return true;


}
bool Queue::dequeue( Customer& item)
{
	if (isempty())
		return false;
	item = front->item;
	Node* temp;
	temp = front;
	front = front->next;
	delete temp;
	items--;
	if (items == 0)
		rear = nullptr;
	return true;


}
