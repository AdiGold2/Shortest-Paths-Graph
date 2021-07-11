#include "Pair.h"

Pair::Pair(int _data, float _key)
{
	data = _data;
	key = _key;
}
Pair::Pair(const Pair& other)
{
	*this = other;
}
void Pair::operator=(const Pair& other)
{
	this->data = other.data;
	this->key = other.key;
}
