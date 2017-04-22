// ===============================================================================
// Project Name        :    Graph
// Project Description :
// ===============================================================================
// Filename Name       :
// Class Version       :    v1.0.0
// Class Description   :
// Author              :    Xefvan
// Email               :	tutuxsfly@126.com
// Create Time         :    2017/4/16 22:50
// Update Time         :
// ===============================================================================

#ifndef STRUCTURE_GRAPHIC_H__
#define STRUCTURE_GRAPHIC_H__

#include <memory>
#include <vector>

// 节点结构
struct Node
{
	char m_cData;
	bool m_bIsVisited;

	Node(char data = 0) : m_cData(data), m_bIsVisited(false) { }
};

// 边的结构
struct Edge
{
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	bool m_bSelected;

	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0)
		: m_iNodeIndexA(nodeIndexA), m_iNodeIndexB(nodeIndexB),
		  m_iWeightValue(weightValue), m_bSelected(false) { }
		  
};

class Graph
{
public:
	explicit Graph(int capacity);
	// ~Graph();
	bool addNode(Node* pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row, int col, int val);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val);
	void printMatrix();
	void depthFirstTraverse(int nodeIndex);
	// void bfs(int nodeIndex);
	void breadthFirstTraverse(int nodeIndex);
	void primTree(int nodeIndex);
	void kruskalTree();

private:
	bool getValueFromMatrix(int row, int col, int& val);
	void breadthFirstTraverseImpl(std::vector<int> preVec);
	int getMinEdge(std::vector<Edge> edgeVec);
	bool isInSet(std::vector<int> nodeSet, int target);
	void mergeNodeSet(std::vector<int>& nodeSetA, std::vector<int> nodeSetB);

private:
	int m_iCapacity;
	int m_iNodeCount;
	const std::unique_ptr<Node[]> m_pNodeArray;
	const std::unique_ptr<Edge[]> m_pEdget;
	std::vector<int> m_vMatrix;
};

#endif // STRUCTURE_GRAPHIC_H__