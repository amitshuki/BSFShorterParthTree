#pragma once
#include "List.h"
class vertex
{
public:
	static const unsigned int   MAX_INT = 0xFFFFFFFF;
	unsigned int verNumber=777;
	List* listOfneighbor;
	unsigned int distanceFromS=MAX_INT;
public:
	int getNumber()
	{
		return verNumber;

	}

	vertex(int number)
	{
		verNumber = number;
		listOfneighbor = new List();
		distanceFromS = MAX_INT;
	}
	~vertex()
	{
	
	}
	void addneighbor(int numOfVertex)
	{
		listOfneighbor->addToHead(numOfVertex);
	}
	vertex()
	{
		listOfneighbor = new List();
		distanceFromS = MAX_INT;
	
	}
};

