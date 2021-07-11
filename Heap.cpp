#include "heap.h"

heap::heap(int max)
{
	heapArr = new Pair[max];
	maxSize = max;
	heapSize = 0;
	allocated = true;
}
heap::heap(Pair* arr, int size)
{
	placeArr = new int[size];
	heapSize = maxSize = size;
	heapArr = arr;
	allocated = false;
	for (int i = (size / 2) - 1; i >= 0; i--)
		FixHeap(i);
	for (int i = 0; i < size; i++)
		placeArr[heapArr[i].GetData()] = i;
}
heap::~heap()
{
	if (allocated)
		delete[] heapArr;
	heapArr = nullptr;
}
void heap::FixHeap(int node)
{
	int M = node;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (heapArr[left].GetKey() < heapArr[node].GetKey()))
		M = left;
	if ((right < heapSize) && (heapArr[right].GetKey() < heapArr[node].GetKey()))
		M = ((heapArr[left].GetKey() < heapArr[right].GetKey()) ? left : right);
	if (M != node)
	{
		int vertexA = heapArr[node].GetData(), vertexB = heapArr[M].GetData();
		swap(heapArr[node], heapArr[M]);
		swap(placeArr[vertexA], placeArr[vertexB]);
		FixHeap(M);
	}
}
Pair heap::Min()
{
	return heapArr[0];
}
Pair heap::DeleteMin()
{
	if (heapSize < 1)
		exit(-1);
	Pair min = heapArr[0];
	heapSize--;
	int name = heapArr[heapSize].GetData();
	heapArr[0] = heapArr[heapSize];
	placeArr[name] = 0;
	FixHeap(0);
	return min;
}
void heap::Insert(Pair node)
{
	if (heapSize == maxSize)
		exit(-1);
	int i = heapSize;
	heapSize++;
	while ((i > 0) && (heapArr[Parent(i)].GetKey() > node.GetKey()))
	{
		heapArr[i] = heapArr[Parent(i)];
		i = Parent(i);
	}
	heapArr[i] = node;
}
int heap::Left(int node)
{
	return (2 * node + 1);
}
int heap::Right(int node)
{
	return (2 * node + 2);
}
int heap::Parent(int node)
{
	return ((node - 1) / 2);
}
void heap::DecreaseKey(int place, float key)
{
	float tempFloat;
	int tempInt;
	heapArr[place].SetKey(key);
	while ((place > 0) && (heapArr[Parent(place)].GetKey() > heapArr[place].GetKey()))
	{
		int parent = Parent(place);
		int vertexA = heapArr[place].GetData(), vertexB = heapArr[parent].GetData();
		tempFloat = heapArr[place].GetKey();
		tempInt = heapArr[place].GetData();
		heapArr[place].SetData(heapArr[parent].GetData());
		heapArr[place].SetKey(heapArr[parent].GetKey());
		heapArr[parent].SetData(tempInt);
		heapArr[parent].SetKey(tempFloat);
		swap(placeArr[vertexA], placeArr[vertexB]);
		place = parent;
	}
}
int heap::GetPlace(int n)
{
	return placeArr[n];
}