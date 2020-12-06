#include "matrix.h"
#include <cmath>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	//输入矩阵m1
	Matrix m1(2, 3);
	cin >> m1;
	cout << endl;
	cout << m1 << endl;

	//输入矩阵m2
	Matrix m2(3, 2);
	cin >> m2;
	cout << endl;
	cout << m2 << endl;

	//矩阵m1与m2相乘
	Matrix m0 = m1 * m2;
	cout << m0 << endl;

	//矩阵m1右乘一个常数
	Matrix m3 = m1 * 2.0;
	cout << m3 << endl;

	//矩阵m1左乘一个常数
	Matrix m4 = 3.0 * m1;
	cout << m4 << endl;

	//对矩阵m3进行浅拷贝输出 (矩阵元素指针指向同一块内存空间)
	Matrix m5 = m3;
	cout << m5 << endl;
	return 0;
}