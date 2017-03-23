/*
	活动选择问题

		假定有一个n个活动的集合S = {a1, a2, a3, ... , an}，这些活动使用同一个资源（例如一个阶梯教室），而这个
	资源在某个时刻只能供一个活动使用。每个活动ai都有一个开始时间si和一个结束时间fi，其中0 <= si <= fi < ∞。如果
	被选中，任务ai发生在半开时间区间[si, fi)期间。如果两个活动ai和aj满足[si, fi)和[sj, fj)不重叠，则称它们是兼
	容的。在活动选择问题中，我们希望选出一个最大兼容活动集。
				假定活动已按结束时间的单调递增顺序排序：
				f1 <= f2 <= f3 <= f4 <= ..... <= fn
	例如：
		ai |	1|		2|		3|		4|		5|		6|		7|		8|		9|		10|		11|
		si |	1|		3|		0|		5|		3|		5|		6|		8|		8| 		 2|		12|
		fi |	4|		5|		6|		7|		9|	    9|	   10|	   11|	   12| 		14|		16|

		子集{a3, a9, a11}又相互兼容的活动组成。但它不是一个最大集，因为子集{a1, a4, a8, a11}更大。实际上
	{a1, a4, a8, a11}和{a2, a4, a9, a11}都是最大兼容活动子集
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 递归贪心算法
string recursive_activity_selector(const vector<int>& start_time,
                                   const vector<int>& finish_time,
                                   int begin, int end)
{
	int index = begin + 1;
	while (index <= end && start_time[index] < finish_time[begin]) {
		++index;
	}

	if (index <= end) {
		return to_string(index) + (index < end ? " " : "") +
		       recursive_activity_selector(start_time, finish_time, index, end);
	}
	return "";
}

// 迭代贪心算法
vector<int> greedy_activity_selector(const vector<int>& start_time,
                                     const vector<int>& finish_time)
{
	vector<int> result;
	result.push_back(1);
	int len = start_time.size() - 1;
	int k_finish = 1;
	for(int index = 2; index <= len; ++index) {
		if(start_time[index] >= finish_time[k_finish]) {
			result.push_back(index);
			k_finish = index;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<int> start_time = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	vector<int> finish_time = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

	cout << recursive_activity_selector(start_time, finish_time, 0, start_time.size() - 1) << endl;

	vector<int> result = greedy_activity_selector(start_time, finish_time);
	for(auto i : result) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}