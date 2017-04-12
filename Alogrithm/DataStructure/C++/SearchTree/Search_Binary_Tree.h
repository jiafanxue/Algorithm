//===============================================================
//USER NAME:          Xefvan
//FILE NAME:
//===============================================================

#include <iostream>
using namespace std;

void print(Search_Tree_Node* x)
{
	cout << "The tree node's value: " << x->value << endl;
}

// 搜索二叉树的结构定义
struct Search_Tree_Node
{
	int value;
	Search_Tree_Node* parent;
	Search_Tree_Node* left;
	Search_Tree_Node* right;

	Search_Tree_Node() : value(), parent(nullptr), left(nullptr), right(nullptr) { }
	Search_Tree_Node(int val, Search_Tree_Node* pParent, Search_Tree_Node* pLeft, Search_Tree_Node* pRight)
		: value(val), parent(pParent), left(pLeft), right(pRight) { }
};

// 搜索二叉树的遍历
void inorder_tree_walk(Search_Tree_Node* x)
{
	if (x != nullptr) {
		inorder_tree_walk(x->left);
		print(x);
		inorder_tree_walk(x->right);
	}
}

// 搜索二叉树的查找
Search_Tree_Node* Tree_search(Search_Tree_Node* x, int key)
{
	if (x == nullptr || key == x->value) {
		return x;
	}

	if (key < x->value) {
		return Search_Tree_Node(x->left, key);
	}
	else {
		return Search_Tree_Node(x->right, key);
	}
}

Search_Tree_Node* Tree_search_2(Search_Tree_Node* x, int key)
{
	while(x != nullptr && k != x->value) {
		if(k < x->value) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}


// 线索二叉树的最小值
Search_Tree_Node* Tree_minimum(Search_Tree_Node* x)
{
	while (x->left != nullptr) {
		x = x->left;
	}
	return x;
}

// 线索二叉树的最大值
Search_Tree_Node* Tree_maximum(Search_Tree_Node* x)
{
	while (x->right != nullptr) {
		x = x->right;
	}
	return x;
}

// 线索二叉树中利用中序遍历查找节点的后继
Search_Tree_Node* Tree_successor(Search_Tree_Node* x)
{
	// 情况一
	if (x->right != nullptr) {
		return Tree_minimum(x->right);
	}

	// 情况二
	Search_Tree_Node* y = x->parent;
	while (y != nullptr && y->right == x) {
		x = y;
		y = y->parent;
	}
	return y;
}

// 线索二叉树中利用中序遍历查找节点的前驱
Search_Tree_Node* Tree_predecessor(Search_Tree_Node* x)
{
	// 情况一
	if (x->left != nullptr) {
		return Tree_maximum(x->left);
	}

	// 情况二
	Search_Tree_Node* y = x->parent;
	while (y != nullptr && y->left == x) {
		x = y;
		y = y->parent;
	}
	return y;
}

// 搜索二叉树的插入
void Tree_insert(Search_Tree_Node* T, Search_Tree_Node* z)
{
	Search_Tree_Node* y = nullptr;
	Search_Tree_Node* x = T;
	while (x != nullptr) {
		y = x;
		if (z->value < x->value) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	z->parent = y;
	if (y == nullptr) {
		T = z;			// tree T is empty
	}
	else if (z->value < y->value) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}

void Transplant(Search_Tree_Node* T, Search_Tree_Node* u, Search_Tree_Node* v)
{
	if (u->parent == nullptr) {
		T = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}

	if (v != nullptr) {
		v->parent = u->parent;
	}
}

// 搜索二叉树的删除
void Tree_delete(Search_Tree_Node* T, Search_Tree_Node* z)
{
	if (z->left == nullptr) {
		Transplant(T, z, z->right);
	}
	else if (z->right == nullptr) {
		Transplant(T, z, z->left);
	}
	else {
		Search_Tree_Node* y = Tree_minimum(z->right);
		if (y->parent != z) {
			Transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}