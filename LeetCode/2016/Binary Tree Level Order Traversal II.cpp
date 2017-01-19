#include <iostream>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> tmp;
    	

        return tmp;
    }
};

int main()
{
	vector<int> vec;
	TreeNode* first = new TreeNode(3);
	TreeNode* second = new TreeNode(9);
	TreeNode* thrid = new TreeNode(20);
	TreeNode* four = new TreeNode(15);
	TreeNode* five = new TreeNode(7);
	first->left = second;
	first->right = thrid;
	thrid->left = four;
	thrid->right = five;

	Solution su;
	cout << "[" << endl;
	for(unsigned i = 0; i < su.levelOrderBottom(first).size(); i++)
	{
		cout << "[";
		for(unsigned j = 0; j < (su.levelOrderBottom(first)[i]).size(); j++) {
			cout << su.levelOrderBottom(first)[i][j] << ", ";     
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	return 0;

}