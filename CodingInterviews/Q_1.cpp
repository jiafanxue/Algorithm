/*
题目：
	如下为类型CMyString的声明，请为该类型添加赋值运算符函数
*/
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

	// 1)
	CMyString& operator=(const CMyString& str)
	{
		if(this == &str) {
			return *this;
		}
		delete[] m_pData;
		m_pData = new char[strlen(str.m_pData) + 1];	// 如果此时内存不足导致new char抛出异常，
														// m_pData将是一个空指针
		strcpy(m_pData, str.m_pData);
		return *this;
	}

	// 2)
	// 这种用法有点高级，先用一个临时实例strTemp，接着把strTemp.m_pData与实例自身m_pData作交换
	// 当离开if时，临时实例strTemp调用析构函数，而strTemp.m_pData所指向的内存就是实例之前m_pData
	// 的内存，所以释放了实例的内存。
	CMyString& operator=(const CMyString& str)
	{
		if(this != &str) {
			CMyString strTemp(str);
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = pTemp;
		}
		return *this;
	}

private:
	char* m_pData;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}