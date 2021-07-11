#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"

class List
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	List() {}
	~List()
	{
		Node* curr = head, *tmp;
		while (curr)
		{
			tmp = curr;
			curr = curr->GetNext();
			delete tmp;
		}
	}

	/******SETTERS******/
	void SetHead(Node* node) { head = node; }
	void Settail(Node* node) { tail = node; }

	/******GETTERS******/
	Node* GetHead() { return head; }
	Node* GetTail() { return tail; }

	void AddItemToTail(int data, float weight)  //creates new Node and adds it to thr end of list
	{
		Node* newNode = new Node(data, weight);
		if (IsEmpty())                        //the new Node is the first item in the list
			head = tail = newNode;
		else
		{
			tail->SetNext(newNode);
			tail = newNode;
		}
		
	}
	Node* RemoveNode(int key)
	{
		Node* curr = head;
		if (head->GetData() == key)    //the head is the item to remove
		{
			head = head->GetNext();
			return curr;
		}
		while (curr->GetNext() != nullptr)   //going over the list and searching for the item to remove
		{
			if ((curr->GetNext())->GetData() == key)
			{
				curr->SetNext((curr->GetNext())->GetNext());
				return curr->GetNext();
			}
		}
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
};