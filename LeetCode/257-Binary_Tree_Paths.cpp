/*
Question:
	Given a binary tree, return all root-to-leaf paths.
	
	For example, given the following binary tree.
	
			1
		  /   \
		 2     3 
		  \
		   5

	All root-to-leaf paths are:

	["1->2->5", "1->3"]
*/
#include <iostream>
#include <vector>
#include <string>
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
	void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
		if(!root->left && !root->right) {
			result.push_back(t);
			return;
		}
		if(root->left)
			binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
		if(root->right)
			binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;

		if(!root) {
			return result;
		}

		binaryTreePaths(result, root, to_string(root->val));

		return result;
	}
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

	first->left = second;
	first->right = third;
	second->left = four;
	second->right = five;

	TreeNode* temps = first;
	printTree(temps);
	cout << endl;

	Solution su;

	vector<string> vec_str = su.binaryTreePaths(first);

	unsigned size = vec_str.size();
	cout << "[";
	for(unsigned i = 0; i < size; ++i) {
		if(i != size - 1) {
			cout << vec_str[i] << ",";	
		}
		else {
			cout << vec_str[i];
		}
	}
	cout << "]" << endl;
	return 0;
}