#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

class AdjacencyList
{
private:
	int numOfVertex = 0;
	List** list = nullptr;
public:
	AdjacencyList(int n);
	~AdjacencyList();

	/******SETTERS******/
	void SetNumOfVertex(int n) { numOfVertex = n; }
	void SetList(List** L) { list = L; }

	/******GETTERS******/
	int GetNumOfVertex() { return numOfVertex; }
	List** GetList() { return list; }

	bool IsAdjacent(int u, int v);
	List* GetAdjList(int u);
	void AddEdge(int u, int v, float c);
	void RemoveEdge(int u, int v);
	//void DijkstraHeap(float* distances);
};