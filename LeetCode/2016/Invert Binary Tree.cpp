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
    TreeNode* invertTree(TreeNode* root) {
    	/* the code can't pass in LeetCode OJ*/
        /*if(root == NULL)
        	return root;

        if(root->left && root->right)
        {
        	TreeNode* temps = root->left;
        	root->left = root->right;
        	root->right = temps;
        }
        invertTree(root->left);
        invertTree(root->right);

        return root;*/

        if(root != NULL)
        {
        	TreeNode* temp = root->left;
        	root->left = root->right;
        	root->right = temp;
         	
        	invertTree(root->left);
        	invertTree(root->right);
        }
        return root;
    }
};


void visit(TreeNode* root)
{
	cout << root->val << " ";
}

void inOrder(TreeNode* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		visit(root);
		inOrder(root->right);
	}

}


int main(int argc, char const *argv[])
{
	
	TreeNode tree1(4);
	TreeNode tree2(2);
	TreeNode tree3(7);
	TreeNode tree4(1);
	TreeNode tree5(3);
	TreeNode tree6(6);
	TreeNode tree7(9);

	tree1.left = &tree2;
	tree1.right = &tree3;
	tree2.left = &tree4;
	tree2.right = &tree5;
	tree3.left = &tree6;
	tree3.right = &tree7;

	inOrder(&tree1);

	Solution su;
	su.invertTree(&tree1);

	cout << endl;

	inOrder(&tree1);

	return 0;
}