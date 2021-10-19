#pragma once
#include"List.h"
class Queue
{
private:
	List listOfVertex;
public:
	Queue()
	{
		
	}
	~Queue()
	{

	}
	
	void Enqueue(int numToinsert);
	int Dequeue();
	bool IsEmpty();
	

};

