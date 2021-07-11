#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	float weight;
	Node* next;
public:
	Node(int _data, float _weigth)
	{
		data = _data;
		weight = _weigth;
		next = nullptr;
	}
	~Node() {}

	/******SETTERS******/
	void SetData(int data) { this->data = data; }
	void SetWeight(float weight) { this->weight = weight; }
	void SetNext(Node* next) { this->next = next; }
	
	/******GETTERS******/
	int GetData() { return data; }
	float Getweight() { return weight; }
	Node* GetNext() { return next; }

};