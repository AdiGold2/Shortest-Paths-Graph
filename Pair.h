#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pair
{
private:
	int data;
	float key;
public:
	Pair() {}
	Pair(int _data, float _key);
	~Pair() {}
	Pair(const Pair& other);

	/******GETTERS******/
	int GetData() const { return data; }
	float GetKey() const { return key; }

	/******SETTERS******/
	void SetData(int _data) { data = _data; }
	void SetKey(float _key) { key = _key; }

	void operator=(const Pair& other);
};