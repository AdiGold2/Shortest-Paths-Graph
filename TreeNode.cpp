#include "TreeNode.h"

int TreeNode::counter;
TreeNode::~TreeNode()
{
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}
TreeNode::TreeNode(Pair item, TreeNode* left, TreeNode* right)
{
	val = item;
	left = left;
	right = right;
	counter++;
}
TreeNode::TreeNode(int  vertex, float key)
{
	val.SetData(vertex);
	val.SetKey(key);
	left = nullptr;
	right = nullptr;
	counter++;
}
TreeNode::TreeNode(const TreeNode& other)
{
	*this = other;
}
void TreeNode::operator=(const TreeNode& other)
{
	this->val = other.val;
	this->left = other.left;
	this->right = other.right;
}
