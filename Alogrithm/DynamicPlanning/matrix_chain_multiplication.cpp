/*
	�������˷����⣨N��������ˣ���
		����n�����������A1��A2��A3��A4��...��An)������Ai�Ĺ�ģΪP(i-1) * P(i)��1 <= i <= n��������ȫ���Ż�
	�������ǵļ���ɼ�A1*A2*A3*...*An����Ҫ�����˷���������
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// �����������
// �������A[p][q]��B[q][r]��C[p][r]
// ����C����ʱ���ɱ����˷��Ĵ�����������p*q*r����Ӧ��29�е�i*j*k
vector<vector<int>> matrix_multiply(const vector<vector<int>>& vv_matrixA,
                                    const vector<vector<int>>& vv_matrixB)
{
	vector<vector<int>> vv_matrixC(vv_matrixA.size());
	// ������A�;���B�Ƿ����ݡ���A����������B������ʱ���������
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

// ��̬�滮���������˷������Ž�
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

