#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size)
{
	arrSize = size;
	pairArr = new Pair[size];
	for (int i = 0; i < size; i++)
	{
		pairArr[i].SetData(i);
		pairArr[i].SetKey(INFINITY);
	}
	placeArr = new int[size];
	for (int i = 0; i < size; i++)
		placeArr[pairArr[i].GetData()] = i;
}
ArrayQueue::~ArrayQueue()
{
	if (pairArr)
		delete[] pairArr;
	if (placeArr)
		delete[] placeArr;
}
Pair ArrayQueue::DeleteMin() 
{
	int tempData;
	float tempKey;
	int vertexA = pairArr[minIndex].GetData(), vertexB = pairArr[arrSize-1].GetData();
	tempData = pairArr[minIndex].GetData();
	tempKey = pairArr[minIndex].GetKey();
	pairArr[minIndex].SetData(pairArr[arrSize - 1].GetData());
	pairArr[minIndex].SetKey(pairArr[arrSize - 1].GetKey());
	pairArr[arrSize - 1].SetData(tempData);
	pairArr[arrSize - 1].SetKey(tempKey);
	swap(placeArr[vertexA], placeArr[vertexB]);
	arrSize--;
	UpdateMin();
	return pairArr[arrSize];
}
void ArrayQueue::UpdateMin()
{
	minIndex = 0;
	for (int i = 1; i < arrSize; i++)
	{
		if (pairArr[i].GetKey() < pairArr[minIndex].GetKey())
			minIndex = i;
	}
}
void ArrayQueue::DecreaseKey(int place, float key)
{
	pairArr[place].SetKey(key);
}
int ArrayQueue::GetPlace(int n)
{
	return placeArr[n];
}