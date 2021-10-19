#include"Graph.h"

int main()
{
	Graph G;


	G.BFSAlgoWithQueue(G.startVertex);


	Graph Gs = G;


	Gs.removeNonConditionEdge();


	Graph* GsT = Gs.transpose();


	GsT->BFSAlgoWithQueue(G.destVertex);


	Graph* Ht = GsT->deleteUnreachbleEdge();


	Graph* h = Ht->transpose();
	h->PrintGraph();
	

}