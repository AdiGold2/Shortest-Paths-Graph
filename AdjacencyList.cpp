#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int n)
{
	numOfVertex = n;
	list = new List * [n];
	for (int i = 0; i < n; i++)
	{
		list[i] = new List;
	}
}
AdjacencyList::~AdjacencyList()
{
	if (list)
	{
		for (int i = 0; i < numOfVertex; i++)
			delete list[i];
		delete list;
	}
}
bool AdjacencyList::IsAdjacent(int u, int v)
{
	if (list[u]->IsEmpty())
	{
		return false;
	}
	Node* curr = list[u]->GetHead();    //going over all of u's neighbors and check if v is one of them
	while (curr != nullptr)
	{
		if (curr->GetData() == v)
			return true;
		curr = curr->GetNext();
	}
	return false;
}
List* AdjacencyList::GetAdjList(int u)
{
	return list[u];
}
void AdjacencyList::AddEdge(int u, int v, float c)
{
	if (u > numOfVertex || v > numOfVertex || c < 0 || u == v) //edges are not in the range / weight is negative / self edge
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	if (IsAdjacent(u, v)) //edge already exist
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	list[u]->AddItemToTail(v, c);
}
void AdjacencyList::RemoveEdge(int u, int v)
{
	list[u]->RemoveNode(v);
}