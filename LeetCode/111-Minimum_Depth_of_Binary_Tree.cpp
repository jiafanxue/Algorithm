/*
Question:
	Given a binary tree, find its minimum depth.
		
	The minimum depth is the number of nodes along the shortest path the root node down to 
	the nearest leaf node.

	e.g.
			1
		   / \
		  2   3
		 / \ 
		4   5
	   /
	  6

	return 2
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if(!root) 
			return 0;
		if(!root->left)
			return 1 + minDepth(root->right);
		if(!root->right)
			return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
    }
	// int minDepth(TreeNode* root) {
	// 	if(!root)
	// 		return 0;
	// 	queue<TreeNode*> Q;
	// 	Q.push(root);
	// 	int i = 0;
	// 	while(!Q.empty()) {
	// 		i++;
	// 		int k = Q.size();
	// 		for(int j = 0; j < k; ++j) {
	// 			TreeNode* rt = Q.front();
	// 			if(rt->left) Q.push(rt->left);
	// 			if(rt->right) Q.push(rt->right);
	// 			Q.pop();
	// 			if(rt->left == NULL && rt->right == NULL) return i;
	// 		}
 // 		}
 // 		return -1;
	// }
};

void printTree(TreeNode* root)
{
	if(root) {
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
	}
}

int main(int argc, char const *argv[])
{
	TreeNode* first = new TreeNode(1);
	TreeNode* second = new TreeNode(2);
	TreeNode* third = new TreeNode(3);
	TreeNode* four = new TreeNode(4);
	TreeNode* five = new TreeNode(5);
	TreeNode* six = new TreeNode(6);

	first->left = second;
	first->right = third;
	second->left = four;
	second->right = five;
	four->left = six;

	TreeNode* temps = first;
	printTree(temps);
	cout << endl;

	Solution su;
	TreeNode* tmp = first;
	cout << su.minDepth(tmp) << endl;

	return 0;
}