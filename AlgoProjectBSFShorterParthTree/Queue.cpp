#include "Queue.h"

void Queue::Enqueue(int numToinsert)
{
	listOfVertex.addtoTail(numToinsert);
}
int Queue::Dequeue() 
{
	if (IsEmpty())
	{
		throw "EmptyQueue";
	}


	int returnVal = listOfVertex.head->vertexNumber;
	List::node* curr = listOfVertex.head->next;
	listOfVertex.deleteNode(listOfVertex.head->vertexNumber);
	listOfVertex.head = curr;
	return returnVal;
}
bool Queue::IsEmpty() 
{
	bool res = false;
		if (listOfVertex.head == nullptr) {
		res = !res;
	}
	return res;
}

