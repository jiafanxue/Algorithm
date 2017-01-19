#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = 0;
        if(root->left && root->left->left == NULL && root->left->right == NULL)
        {
            left = root->left->val;
        }
        else
        {
            left = sumOfLeftLeaves(root->left);
        }
        int right = sumOfLeftLeaves(root->right);
        return left + right;
    }
};

int main()
{
	

    TreeNode tree1(4);
    TreeNode tree2(2);
    TreeNode tree3(7);
    TreeNode tree4(2);
    TreeNode tree5(3);
    TreeNode tree6(6);
    TreeNode tree7(9);

    tree1.left = &tree2;
    tree1.right = &tree3;
    tree2.left = &tree4;
    tree2.right = &tree5;
    tree3.left = &tree6;
    tree3.right = &tree7;

    Solution su;
    cout << su.sumOfLeftLeaves(&tree1) << endl;


	return 0;
}