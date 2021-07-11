#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
class TreeNode
{
private:
	Pair val;
	TreeNode* left = nullptr, * right = nullptr;
public:
	static int counter;
	TreeNode() { counter++; }
	TreeNode(Pair item, TreeNode* left, TreeNode* right);
	TreeNode(int  vertex, float key);
	TreeNode(const TreeNode& other);
	~TreeNode();

	/*****Getters*****/
	Pair& GetVal() { return val; }
	int GetData() const { return val.GetData(); }
	float GetKey() const { return val.GetKey(); }
	TreeNode* GetLeft() const { return left; }
	TreeNode* GetRight() const { return right; }

	/*****Setters*****/
	bool SetVal(Pair item) { val = item; return true; }
	bool SetLeft(TreeNode* L) { left = L; return true; }
	bool SetRight(TreeNode* R) { right = R; return true; }

	bool IsLeaf() const { return (left == nullptr && right == nullptr); }
	void operator=(const TreeNode& other);
};
