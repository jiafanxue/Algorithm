/*
Question:
	Rebuild Binary Tree.
*/
#include <iostream>
using namespace std;

struct Node
{
	Node* pLeft;
	Node* pRight;
	char chValue;
};

/*
	pPreOrder : 以NULL为结尾的前序遍历结果的字符串数组
	pInOrder  : 以NULL为结尾的中序遍历结果的字符串数组
	nTreeLen  : 树的长度  
	pRoot     : 返回Node**类型，根据前序遍历和中序遍历结果重新构建树的根节点

	e.g.
		pPreOrder : a b d c e f
		pInOrder  : d b a e c f
	
			a
		   / \
		  b   c
		 /   / \
		d   e   f
*/
void Rebuild(char* pPreOrder, char* pInOrder, int nTreeLen, Node** pRoot)
{
	// 检查边界条件
	if(pPreOrder == NULL || pInOrder == NULL) {
		return;
	}

	// 获得前序遍历的第一个节点
	Node* pTemp = new Node;
	pTemp->chValue = *pPreOrder;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;

	// 如果节点为空，把当前节点复制到根节点
	if(*pRoot == NULL) {
		*pRoot = pTemp;
	}
	
	// 如果当前树长度为1，那么已经是最后一个节点了
	if(nTreeLen == 1) {
		return;
	}

	// 寻找子树长度
	char* pOrgInOrder = pInOrder;
	char* pLeftEnd = pInOrder;
	int nTempLen = 0;

	// 找到左子树的结尾
	while(*pPreOrder != *pLeftEnd) {
		if(pPreOrder == NULL || pLeftEnd == NULL) {
			return;
		}

		nTempLen++;

		// 记录临时长度，以免溢出
		if(nTempLen > nTreeLen) {
			break;
		}

		pLeftEnd++;
	} 

	// 寻找左子树长度
	int nLeftLen = 0;
	nLeftLen = (int)(pLeftEnd - pOrgInOrder);

	// 寻找右子树长度
	int nRightLeft = 0;
	nRightLeft = nTreeLen - nLeftLen - 1;

	// 重建左子树
	if(nLeftLen > 0) {
		Rebuild(pPreOrder + 1, pInOrder, nLeftLen, &((*pRoot)->pLeft));
	}

	// 重建右子树
	if(nRightLeft > 0) {
		Rebuild(pPreOrder + nLeftLen + 1, pInOrder + nLeftLen + 1, nRightLeft, &((*pRoot)->pRight));
	}
}

void preOrder(Node* pRoot)
{
	if(pRoot != NULL) {
		cout << pRoot->chValue << " ";
		preOrder(pRoot->pLeft);
		preOrder(pRoot->pRight);
	}
}

void inOrder(Node* pRoot)
{
	if(pRoot != NULL) {
		inOrder(pRoot->pLeft);
		cout << pRoot->chValue << " ";
		inOrder(pRoot->pRight);
	}
}

int main(int argc, char const *argv[])
{
	char pPreOrder[] = {'a', 'b', 'd', 'c', 'e', 'f'};
	char pInOrder[] = {'d', 'b', 'a', 'e', 'c', 'f'};
	int nTreeLen = 6;
	Node* pRoot = NULL;
	Rebuild(pPreOrder, pInOrder, nTreeLen, &pRoot);
	Node* tmp = pRoot;
	preOrder(tmp);
	cout << endl;
	Node* tmp_2 = pRoot;
	inOrder(tmp_2);
	cout << endl;
	return 0;
}