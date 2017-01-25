/*
Question:
	Hierarchical traversal
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int value_) : value(value_), left(NULL), right(NULL) {}
};

/*
	Answer one
*/
int PrintNodeAtLevel(Node* root, int level)
{
	if(!root || level < 0) {
		return 0;
	}

	if(level == 0) {
		cout << root->value << " ";
		return 1;
	}

	return PrintNodeAtLevel(root->left, level - 1) + PrintNodeAtLevel(root->right, level - 1);
}

void PrintNodeByLevel_1(Node* root)
{
	for(int level = 0; ; level++) {
		if(!PrintNodeAtLevel(root, level)) {
			break;
		}
		cout << endl;
	}
}

/*
	Answer two
*/
void PrintNodeByLevel_2(Node* root)
{
	if(root == NULL) {
		return;
	}

	vector<Node*> vec;

	vec.push_back(root);
	int cur = 0;
	int last = -1;
	while(cur < (int)vec.size()) {
		last = vec.size();

		while(cur < last) {
			cout << vec[cur]->value << " ";
			if(vec[cur]->left) {
				vec.push_back(vec[cur]->left);
			} 
			if(vec[cur]->right) {
				vec.push_back(vec[cur]->right);
			}
			cur++;
		}
		cout << endl;
	}
}

/*
	Answer three
*/
void PrintNodeByLevel_3(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(0);
	while(!q.empty()) {
		Node* tmp = q.front();
		q.pop();
		if(tmp != NULL) {
			cout << tmp->value << " ";
			if(tmp->left != NULL) {
				q.push(tmp->left);
			}
			if(tmp->right != NULL) {
				q.push(tmp->right);
			}
		}
		else if(!q.empty()) {
			q.push(0);
			cout << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* four = new Node(4);
	Node* five = new Node(5);
	Node* six = new Node(6);
	Node* seven = new Node(7);
	Node* eight = new Node(8);

	first->left = second;
	first->right = third;
	second->left = four;
	second->right = five;
	third->right = six;
	five->left = seven;
	five->right = eight;

	Node* tmp = first;
	PrintNodeByLevel_1(tmp);
	cout << endl;
	Node* tmp2 = first;
	PrintNodeByLevel_2(tmp2);
	cout << endl;
	Node* tmp3 = first;
	PrintNodeByLevel_3(tmp3);
	cout << endl;
	return 0;
}
