#include "matrix.h"
#include <cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

int main()
{
	//�������m1
	Matrix m1(2, 3);
	cin >> m1;
	cout << endl;
	cout << m1 << endl;

	//�������m2
	Matrix m2(3, 2);
	cin >> m2;
	cout << endl;
	cout << m2 << endl;

	//����m1��m2���
	Matrix m0 = m1 * m2;
	cout << m0 << endl;

	//����m1�ҳ�һ������
	Matrix m3 = m1 * 2.0;
	cout << m3 << endl;

	//����m1���һ������
	Matrix m4 = 3.0 * m1;
	cout << m4 << endl;

	//�Ծ���m3����ǳ������� (����Ԫ��ָ��ָ��ͬһ���ڴ�ռ�)
	Matrix m5 = m3;
	cout << m5 << endl;
	return 0;
}