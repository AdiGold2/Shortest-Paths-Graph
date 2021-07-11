#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <iomanip>

class AdjacencyMatrix
{
private:
	int numOfVertex = 0;
	float** matrix = nullptr;

public:
	AdjacencyMatrix(int n);
	~AdjacencyMatrix();

	/******SETTERS******/
	void SetNumOfVertex(int n) { numOfVertex = n; }
	void SetMatrix(float** mat) { matrix = mat; }

	/******GETTERS******/
	int GetNumOfVertex() { return numOfVertex; }
	float** GetMatrix() { return matrix; }

	void MakeEmptyGraph();
	bool IsAdjacent(int u, int v);
	List* GetAdjList(int u);
	void AddEdge(int u, int v, float c);
	void RemoveEdge(int u, int v);
	void PrintMat();
};