#pragma once
#include "vertex.h"
#include "List.h"
#include "Queue.h"
#include <iostream>


class Graph
{
public:
	
	vertex* arrayOfVertex;

	int numOfVertex = 0;
	int startVertex = 0;
	int destVertex = 0;

	void MakeEmptyGraph(int numberOfVer);
	bool IsAdjacent(int u, int v);
	List* getAdjList(int u);
	void RemoveEdge(int u, int v);

	Graph() {
		std::cin >> numOfVertex;
		std::cin >> startVertex;
		std::cin >> destVertex;
		ReadGraph();
	}
	Graph(const Graph& graph)
	{
		numOfVertex = graph.numOfVertex;
		startVertex = graph.startVertex;
		destVertex = graph.destVertex;
		arrayOfVertex = new vertex[numOfVertex];
		for (int i = 0; i < numOfVertex; i++) {
			this->arrayOfVertex[i] = graph.arrayOfVertex[i];
			this->arrayOfVertex[i].listOfneighbor = new List();
			List::node* curr = graph.arrayOfVertex[i].listOfneighbor->head;
			while (curr)
			{
				arrayOfVertex[i].listOfneighbor->addToHead(curr->vertexNumber);
				curr = curr->next;
			}
		}
	}
	Graph(int sizeOfVertex, int i_startVertex, int i_destVertex)
	{
		numOfVertex = sizeOfVertex;
		startVertex = i_startVertex;
		destVertex = i_destVertex;
		arrayOfVertex = new vertex[numOfVertex];
	}
	~Graph()
	{
		for (int i = 0; i < numOfVertex; i++)
		{
			delete (arrayOfVertex[i].listOfneighbor);
		}
		delete[] arrayOfVertex;
	}
	void ReadGraph();
	void PrintGraph();
	int isEmpty();
	int AddEdge(int i, int j);
	bool isValidEdge(int i, int j);
	void deleteAdj(int vertexFrom, int numToDelete);
	void BFSAlgoWithQueue(int startIndex);
	void removeNonConditionEdge();
	Graph* transpose();
	Graph* deleteUnreachbleEdge();

};

