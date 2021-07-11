#pragma once
#include "heap.h"
#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "ArrayQueue.h"
#include <fstream>
#include <string>
#define MAXSIZE 128
using namespace std;

class Graph
{
private:
	int numOfVertex = 0;
	int startingVertex;
	int destinationVertex;
	AdjacencyList* list = nullptr;
	AdjacencyMatrix* matrix = nullptr;
	float* distances;
public:
	Graph() {}
	~Graph();
	/******SETTERS******/
	void SetNumOfVertex(int num) { numOfVertex = num; }
	void SetStartingVertex(int vertex) { startingVertex = vertex; }
	void SetDestinationVertex(int vertex) { destinationVertex = vertex; }
	void SetList(AdjacencyList* input_list) { list = input_list; }
	void SetMatrix(AdjacencyMatrix* input_matrix) { matrix = input_matrix; }

	/******GETTERS******/
	int GetNumOfVertex() { return numOfVertex; }
	int GetStartingVertex() { return startingVertex; }
	int GetDestinationVertex() { return destinationVertex; }
	AdjacencyMatrix* GetMatrix() { return matrix; }
	AdjacencyList* GetList() { return list; }

	void Init();
	void AddEdge(int u, int v, float c);
	void ReadGraphFromFile(const char* fileName);
	void CheckInputVaildInt(char* toCheck);
	void CheckInputVaildFloat(char* toCheck);

	/*****Algorithms*****/
	void AdjacencyDijkstraHeap();
	void MatrixDijkstraHeap();
	void AdjacencyDijkstraArray();
	void MatrixDijkstraArray();
	void MatrixBellmanFord();
	void AdjacencyBellmanFord();
	bool Relax(int u, int v, float c);
};