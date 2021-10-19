#include "List.h"
void List::addToHead(int vertexNumber)
{
	if (head == nullptr)
	{
		head = new node(vertexNumber);
		tail = head;
	}
	else
	{

		node* p = head;

		head = new node(vertexNumber);
		head->next = p;

	}

}
void List::addtoTail(int vertexNumber)
{
	if (head == nullptr)
	{
		addToHead(vertexNumber);

	}
	else
	{
		node* curr = new node(vertexNumber);
		tail->next = curr;
		tail = curr;

	}

}
List::~List()
{
	node* p = head;
	node* t;
	if (p == nullptr)
	{
		return;
	}
	else
	{
		while (p->next != nullptr)
		{
			t = p->next;
			delete(p);
			p = t;

		}
		delete(p);
	}
	
}

void List::deleteNode(int vertexToDelete)
{
	node* p = head;
	if (head == nullptr)
	{
		std::cout << "ITS EMPTY LIST" << std::endl;

	}
	if (vertexToDelete == head->vertexNumber)
	{
		head = head->next;
		delete(p);

	}
	else
	{
		while (p->next->vertexNumber != vertexToDelete)
		{
			if (p->next == nullptr)
			{
				std::cout << "Not Found";
				break;
			}
			p = p->next;
		}
		node* temp = p->next;

		p->next = temp->next;
		delete(temp);
	}


}



bool List::isExist(int i) {
	bool res = true;
	node* p = head;
	if (head == nullptr)
	{
		res = !res;
	}
	else
	{
		while (p->vertexNumber != i) {
			p = p->next;
			if (p == nullptr) {
				res = false;
				break;
			}
		}

	}

	return res;
}