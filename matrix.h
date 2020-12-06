
#pragma once
#include<iostream>

using namespace std;
class Matrix
{
private:
	int Rows;//矩阵的行
	int Columns;//矩阵的列
	float** MatData;//保存矩阵元素数据的二维数组

public:
	Matrix(int row = 3, int col = 3);

	Matrix(const Matrix& m);

	~Matrix(void);

	int Row() const { return Rows; }//返回行
	int Col() const { return Columns; }//返回列
	void SetSize(int row, int col);//调整数组的大小

	float& operator () (int row, int col);//获取矩阵元素
	float  operator () (int row, int col) const;//重载获取矩阵元素函数，只有const对象能访问
	Matrix& operator = (const Matrix& m);

	
	friend Matrix operator + (const Matrix& m1, const Matrix& m2);
	friend Matrix operator - (const Matrix& m1, const Matrix& m2);
	friend Matrix operator * (const Matrix& m1, const Matrix& m2);
	friend Matrix operator * (const float& num, const Matrix& m1);
	friend Matrix operator * (const Matrix& m1, const float& num);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream &operator<<(ostream&, Matrix&);
	
	
};






