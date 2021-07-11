#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
class heap
{
private:
	Pair* heapArr;
	int maxSize;
	int heapSize;
	bool allocated;
	int* placeArr;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	heap(int max);
	heap(Pair* arr, int size);
	~heap();
	heap(const heap& other) = delete;
	Pair Min();
	Pair DeleteMin();
	void Insert(Pair node);
	void MakeEmpty() { heapSize = 0; }
	bool IsEmpty() { return (heapSize == 0); }
	void operator=(const heap& other) = delete;
	void DecreaseKey(int place, float key);
	int GetPlace(int n);
};