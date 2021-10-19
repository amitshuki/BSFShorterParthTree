#pragma once
#include <iostream>
class List
{
public:
	class node
	{
	public:
		int vertexNumber;
		node* next;

		node(int number) 
		{
			vertexNumber = number;
			next = nullptr;
		}


	};

	node* head;
	node* tail;

	List() {
		head = nullptr;
		tail = nullptr;
	}
	void addToHead(int vertexNumber);
	void addtoTail(int vertexNumber);
	~List();

	void deleteNode(int vertexToDelete);
	bool isExist(int i);
	

};

