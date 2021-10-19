#include "Graph.h"
void  Graph::MakeEmptyGraph(int numberOfVer) {
	numOfVertex = numberOfVer;
	arrayOfVertex = new vertex[numberOfVer];
	for (int i = 0; i < numberOfVer; i++) {
		arrayOfVertex[i] = vertex(i + 1);
	}
}
bool  Graph::IsAdjacent(int u, int v) {
	return arrayOfVertex[u - 1].listOfneighbor->isExist(v);

}
List* Graph::getAdjList(int u)
{
	return(arrayOfVertex[u - 1].listOfneighbor);
}
void  Graph::RemoveEdge(int u, int v) {
	arrayOfVertex[u - 1].listOfneighbor->deleteNode(v);
}

void Graph::ReadGraph()
{
	arrayOfVertex = new vertex[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
	{
		arrayOfVertex->verNumber = i + 1;
	}

	int from=0;
	int to=0;
	while (std::cin>>from) {
		
		std::cin >> to;
		if (from<1 || to<1 || from>numOfVertex || to>numOfVertex)
		{
			std::cout << "invalid input";
				exit(0);
		}
		arrayOfVertex[from - 1].listOfneighbor->addToHead(to);
	}
	if (from == 0 || to == 0)
	{
		std::cout << "invalid input";
		exit(0);
	}

}
void Graph::PrintGraph() {
	if (numOfVertex == 0)
	{
		std::cout << "Graph Empty" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < numOfVertex; i++) {
			List::node* p = arrayOfVertex[i].listOfneighbor->head;
			while (p != nullptr) {
				std::cout << "\t" << i + 1 << "\t" << p->vertexNumber << std::endl;
				p = p->next;
				
			}
				
			

		}
	}
}
int  Graph::isEmpty()
{
	return numOfVertex > 0 ? 0 : 1;
}
int  Graph::AddEdge(int i, int j)
{
	if (isValidEdge(i, j)) {
		arrayOfVertex[i - 1].addneighbor(j);
		return 1;
	}
	else
	{
		return 0;

	}
}
void Graph::deleteAdj(int vertexFrom, int numToDelete)
{
	arrayOfVertex[vertexFrom - 1].listOfneighbor->deleteNode(numToDelete);

}
bool Graph::isValidEdge(int i, int j)
{

	return(i<1 || i>numOfVertex || j<1 || j>numOfVertex);
}
void Graph::BFSAlgoWithQueue(int startIndex)
{
	Queue q;
	for (int i = 0; i < numOfVertex; i++)
	{
		arrayOfVertex[i].distanceFromS = vertex::MAX_INT;
	}
	q.Enqueue(startIndex);
	arrayOfVertex[startIndex - 1].distanceFromS = 0;

	while (!q.IsEmpty())
	{
		int u = q.Dequeue();
		List::node* curr = arrayOfVertex[u - 1].listOfneighbor->head;
		while (curr != nullptr) {
			if (arrayOfVertex[curr->vertexNumber - 1].distanceFromS == vertex::MAX_INT) {
				arrayOfVertex[curr->vertexNumber - 1].distanceFromS = arrayOfVertex[u - 1].distanceFromS + 1;
				q.Enqueue(curr->vertexNumber);
				
			}
			curr = curr->next;
			
		}
	}


}
void Graph::removeNonConditionEdge()
{
	for (int i = 0; i < numOfVertex; i++) {
		List::node* curr = arrayOfVertex[i].listOfneighbor->head;
		List::node* temp = curr;
		bool check = false;
		while (curr != nullptr) {
			check = false;
			if (arrayOfVertex[i].distanceFromS + 1 != (arrayOfVertex[(curr->vertexNumber) - 1].distanceFromS))
			{
				temp = curr->next;
				RemoveEdge(i + 1, curr->vertexNumber);
				curr = temp;
				check = true;
			}
			if(!check)
				curr = curr->next;
		}
	}
}
Graph* Graph::transpose() 
{
	Graph* gt = new Graph(numOfVertex, startVertex, destVertex);
	for (int i = 0; i < numOfVertex; i++) {
		List::node* curr = arrayOfVertex[i].listOfneighbor->head;
		while(curr!=nullptr)
		{
			int data = curr->vertexNumber;
			gt->arrayOfVertex[data - 1].addneighbor(i+1);
			curr = curr->next;
		}
	}
	return gt;
}
Graph* Graph::deleteUnreachbleEdge()
{
	Graph* res = new Graph(*this);
	for (int i = 0; i < numOfVertex; i++)
	{
		if (res->arrayOfVertex[i].distanceFromS == vertex::MAX_INT)
		{
			delete res->arrayOfVertex[i].listOfneighbor;
			res->arrayOfVertex[i].listOfneighbor = new List();
		}
	}
	return res;
}