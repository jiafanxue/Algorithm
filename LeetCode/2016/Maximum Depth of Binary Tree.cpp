#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        	return 0;

        int hl = maxDepth(root->left);
        int hr = maxDepth(root->right);
        if(hl > hr)
        	return ++hl;
        else
        	return ++hr;
    }
};

int main()
{
	TreeNode tree1(1);
	TreeNode tree2(2);
	TreeNode tree3(3);
	TreeNode tree4(4);

	tree1.left = &tree2;
	tree1.right = &tree3;
	tree2.left = &tree4;


	Solution su;
	cout << su.maxDepth(&tree1) << endl;

	return 0;
}