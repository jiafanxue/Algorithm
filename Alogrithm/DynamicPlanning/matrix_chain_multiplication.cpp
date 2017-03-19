/*
	矩阵链乘法问题（N个矩阵相乘）：
		给定n个矩阵的链（A1，A2，A3，A4，...，An)，矩阵Ai的规模为P(i-1) * P(i)（1 <= i <= n），求完全括号化
	方案，是的计算成绩A1*A2*A3*...*An所需要标量乘法次数最少
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// 两个矩阵相乘
// 如过矩阵A[p][q]，B[q][r]则C[p][r]
// 矩阵C所需时间由标量乘法的次数决定，即p*q*r，对应第29行的i*j*k
vector<vector<int>> matrix_multiply(const vector<vector<int>>& vv_matrixA,
                                    const vector<vector<int>>& vv_matrixB)
{
	vector<vector<int>> vv_matrixC(vv_matrixA.size());
	// 检查矩阵A和矩阵B是否相容。即A的列数等于B的行数时，才能相乘
	if (vv_matrixA.size() != vv_matrixB[0].size()) {
		throw "incompatible dimensions";
	}
	else {
		for (unsigned i = 0; i < vv_matrixA.size(); ++i) {
			for (unsigned j = 0; j < vv_matrixB[0].size(); ++j) {
				int tmp = 0;
				for (unsigned k = 0; k < vv_matrixA[0].size(); ++k) {
					tmp += vv_matrixA[i][k] * vv_matrixB[k][j];
				}
				vv_matrixC[i].push_back(tmp);
			}
		}
	}
	return vv_matrixC;
}

// 动态规划求解矩阵链乘法的最优解
// std::pair<vector<vector<int>>, vector<vector<int>>> matrix_chain_order(
// 	const vector<vector<vector<int>>& vvv_table)
// {
// 	int vvv_size = vvv_table.size() - 1;
// 	vector<vector<int>> vv_matrix(vvv_size);
// 	vector<vector<int>> vv_stable(vvv_size);

// 	for(int i = 0; i < vvv_size; ++i) {
// 		vv_matrix[i].reserve(vvv_size);
// 		for(int j = 0; j < n; ++j) {
// 			vv_matrix[i][i] = 0;  
// 		}
//  	}

//  	for(int l = 1; l < vvv_size; ++l) {
//  		for(int i = 0; i < vvv_size - l + 1; ++i) {
//  			int j = i + l - 1;

//  		}
//  	}
// } 


int main(int argc, char const *argv[])
{
	vector<vector<int>> vv_matrixA = {
		{1, 1},
		{1, 1}
	};

	vector<vector<int>> vv_matrixB = {
		{2, 3},
		{4, 5}
	};

	vector<vector<int>> vv_matrixC = matrix_multiply(
	                                     vv_matrixA, vv_matrixB);
	for (unsigned i = 0; i < vv_matrixC.size(); ++i) {
		for (unsigned j = 0; j < vv_matrixC[0].size(); ++j) {
			cout << vv_matrixC[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

