#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
class ArrayQueue
{
private:
	Pair* pairArr;
	int arrSize;
	int minIndex;
	int* placeArr;
public:
	ArrayQueue(int size);
	~ArrayQueue();
	ArrayQueue(const ArrayQueue& other) = delete;
	void operator=(const ArrayQueue& other) = delete;

	/*****Getters*****/
	int GetSize() { return arrSize; }
	int GetMinIndex() { return arrSize; }
	int GetPairArrData(int place) { return pairArr[place].GetData(); }
	float GetPairArrKey(int place) { return pairArr[place].GetKey(); }
	int GetPlace(int n);

	/*****Setters*****/
	void SetArrSize(int toSet) { arrSize = toSet; }
	void SetMinIndex(int toSet) { minIndex = toSet; }
	void SetPairArrData(int place, int i) { pairArr[place].SetData(i); }
	void SetPairArrKey(int place, float i) { pairArr[place].SetKey(i); }

	Pair Min() { return pairArr[minIndex]; }
	Pair DeleteMin();
	void MakeEmpty() { arrSize = 0; }
	bool IsEmpty() { return (arrSize == 0); }
	void DecreaseKey(int place, float key);
	void UpdateMin();
};