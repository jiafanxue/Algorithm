#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        
    }
};

int main()
{
	TreeNode* first = new TreeNode(10);
	TreeNode* second = new TreeNode(5);
	TreeNode* third = new TreeNode(-3);
	TreeNode* four = new TreeNode(3);
	TreeNode* five = new TreeNode(2);
	TreeNode* six = new TreeNode(11);
	TreeNode* seven = new TreeNode(3);
	TreeNode* eight = new TreeNode(-2);
	TreeNode* nine = new TreeNode(1);

	first->left = second;
	first->right = third;
	second->left = four;
	second->right = five;
	third->right = six;
	four->left = seven;
	four->right = eight;
	five->right = nine;

	Solution su;

	cout << su.pathSum(first, 5) << endl;


	return 0;
}