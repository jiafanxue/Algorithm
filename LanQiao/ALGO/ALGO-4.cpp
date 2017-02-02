#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define max(a, b) a > b ? a : b

const int MAX = 100001;

int M;										// 表示边的索引，初始值为0
int head[MAX];								// 表示某个结点所连接的边
int dp[MAX][2];								// dp[x][0]表示第x个结点不选择时最大权值，dp[x][1]表示第x个结点选择时最大权值

struct Edge
{
	int toNode;								// 表示这条边到达的结点
	int nextEdge;							// 表示这条边的出发结点的下一条边
}edge[2 * MAX];								// 一共有n个结点，有n-1条边，但是不同的出发结点算作不同的边，所以有2n-2条边

// 把新边加入边集，构造树
void add(int from, int to)
{
	edge[M].toNode = to;
	edge[M].nextEdge = head[from];
	head[from] = M++;						// head[x]的值可能会被第二次赋值
}

// 类似dfs遍历
void dfs(int node, int preNode)
{
	for(int i = head[node]; i != -1; i = edge[i].nextEdge) {
		if(edge[i].toNode == preNode) {		// 说明这条边已经搜索过了
			continue;
		}
		int toNode = edge[i].toNode;		// 表示边i到达的结点
		dfs(toNode, node);
		dp[node][0] += max(dp[toNode][0], dp[toNode][1]);		// 该结点不算，则该边上的另一结点可选也可以不选
		dp[node][1] += dp[toNode][0];		// 该结点选了，则该边上另一结点就不能选了
	}
}

int main(int argc, char const *argv[])
{
	int n;
	memset(head, -1, sizeof(head));			// 所有边置为-1，表示不存在该边
	memset(dp, 0, sizeof(dp));
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> dp[i][1];					// 每一个结点的权值
	}

	for(int j = 1; j <= n - 1; ++j) {
		int from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}

	dfs(1, 0);								// 从1号结点开始向后动态规划
	int result = max(dp[1][0], dp[1][1]);	// 因为不确定根节点，所有从几号开始动态规划就找几号的状态
	cout << result << endl;

	return 0;
}