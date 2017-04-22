// ===============================================================================
// Project Name        :    Graph
// Project Description :
// ===============================================================================
// Filename Name       :
// Class Version       :    v1.0.0
// Class Description   :
// Author              :    Xefvan
// Email               :	tutuxsfly@126.com
// Create Time         :    2017/4/16 23:00
// Update Time         :
// ===============================================================================

#include "graph.h"
#include <iostream>
#include <queue>
#include <vector>

Graph::Graph(int capacity)
	: m_iCapacity(capacity), m_iNodeCount(0),
	  m_pNodeArray(std::make_unique<Node[]>(m_iCapacity * m_iCapacity)),
	  m_pEdget(std::make_unique<Edge[]>(m_iCapacity - 1)),
	  m_vMatrix(std::vector<int>(m_iCapacity * m_iCapacity, 0))
{

}

bool Graph::addNode(Node* pNode)
{
	if (pNode == nullptr) {
		return false;
	}
	m_pNodeArray[m_iNodeCount++].m_cData = pNode->m_cData;
	return true;
}

void Graph::resetNode()
{
	for (int i = 0; i < m_iCapacity; ++i) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool Graph::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}

	m_vMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}

	m_vMatrix[row * m_iCapacity + col] = val;
	m_vMatrix[col * m_iCapacity + row] = val;
	return true;
}

void Graph::printMatrix()
{
	for (int i = 0; i < m_iCapacity; ++i) {
		for (int j = 0; j < m_iCapacity; ++j) {
			cout << m_vMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
}

void Graph::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for(int i = 0; i < m_iCapacity; ++i) {
		getValueFromMatrix(nodeIndex, i, value);
		if(value == 1) {
			if(m_pNodeArray[i].m_bIsVisited = true) {
				continue;
			}
			else {
				depthFirstTraverse(i);
			}
		}
		else {
			continue;
		}
	}
}

// 队列实现，算法导论
/*void Graph::bfs(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	std::queue<Edge> q;
	q.push(m_pNodeArray[nodeIndex]);
	while(!q.empty()) {
		
	}
}*/


void Graph::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	std::vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);
}

bool Graph::getValueFromMatrix(int row, int col, int& val)
{
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}

	val = m_vMatrix[row * m_iCapacity + col];
	return true;
}

void Graph::breadthFirstTraverseImpl(std::vector<int> preVec)
{
	int value = 0;
	vector<int> curVec;

	for (unsigned j = 0; j < preVec.size(); ++j) {
		for (int k = 0; k < m_iCapacity; ++k) {
			getValueFromMatrix(preVec[j], k, value);
			if (value != 0) {
				if (m_pNodeArray[k].m_bIsVisited == true) {
					continue;
				}
				else {
					cout << m_pNodeArray[k].m_cData << " ";
					m_pNodeArray[k].m_bIsVisited = true;
					curVec.push_back(k);
				}
			}
		}
	}

	if (curVec.size() == 0) {
		return;
	}
	else {
		breadthFirstTraverseImpl(curVec);
	}
}

void Graph::primTree(int nodeIndex)
{

}


