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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }
        if(p && q && (p->val == q->val))
        {
            if(isSameTree(p->left, q->left))
                if(isSameTree(p->right, q->right))
                    return true;
        }
        return false;
    }
};

int main()
{
	

    TreeNode tree1(4), tree1s(4);
    TreeNode tree2(2), tree2s(2);
    TreeNode tree3(7), tree3s(7);
    TreeNode tree4(2), tree4s(2);
    TreeNode tree5(3), tree5s(3);
    TreeNode tree6(6), tree6s(6);
    TreeNode tree7(9), tree7s(9);

    tree1.left = &tree2;
    tree1.right = &tree3;
    tree2.left = &tree4;
    tree2.right = &tree5;
    tree3.left = &tree6;
    tree3.right = &tree7;

    tree1s.left = &tree2s;
    tree1s.right = &tree3s;
    tree2s.left = &tree4s;
    tree2s.right = &tree5s;
    tree3s.left = &tree6s;
    tree3s.right = &tree7s;

    Solution su;
    if(su.isSameTree(&tree1, &tree1s))
    {
        cout << "Same Tree" << endl;
    }
    else
    {
        cout << "No Same Tree" << endl;
    }


	return 0;
}