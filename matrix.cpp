
#include "matrix.h"
#include <cmath>
#include<cstring>
#include<iostream>

using namespace std;

Matrix::Matrix(int row, int col)
{
	Rows = row;
	Columns = col;
MatData = new float* [row];

	for (int i = 0; i < row; i++)
	{
		MatData[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			MatData[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& m)
{
	Rows = m.Row();
	Columns = m.Col();
	MatData = new float* [Rows];

	for (int i = 0; i < Rows; i++)
	{
		MatData[i] = new float[Columns];
		{
			memcpy(MatData[i], m.MatData[i], sizeof(float) * Columns);
		}
	}

}

Matrix::~Matrix(void)//进行特判，避免内存被重复释放
{
	if(!MatData)
	{ }
	else
	{
		for (int i = 0; i < Rows; i++)
		{
			delete[] MatData[i];
			MatData[i] = NULL;

		}
		delete[] MatData;
		MatData = NULL;
	}

}

//返回数组元素（引用返回）
float& Matrix::operator () (int row, int col)
{
	if (row >= Rows || col >= Columns)
	{
		throw("matrix::operator(): Index out of range!");
	}

	return MatData[row][col];
}

float Matrix::operator () (int row, int col) const
{
	if (row >= Rows || col >= Columns)
	{
		throw("matrix::operator(): Index out of range!");
	}

	return MatData[row][col];
}


//重载运算符+
Matrix operator + (const Matrix& m1, const Matrix& m2)
{

	if ((m1.Col() != m2.Col()) || (m1.Row() != m2.Row()))
	{
		throw("matrix::operator+: The two matrix have different size!");
	}

	Matrix matTmp(m1.Row(), m1.Col());
	for (int i = 0; i < m1.Row(); i++)
	{
		for (int j = 0; j < m1.Col(); j++)
		{
			matTmp(i, j) = m1(i, j) + m2(i, j);
		}
	}
	return matTmp;
}


//进行浅拷贝，两个矩阵元素指针指向同一块内存空间
Matrix& Matrix::operator = (const Matrix& m)
{

	this->Columns = m.Columns;
	this->Rows = m.Rows;
	this->MatData = m.MatData;
	return *this;


}


//调整矩阵大小，原有值不变
void Matrix::SetSize(int row, int col)
{
	if (row == Rows && col == Columns)
	{
		return;
	}

	float** rsData = new float* [row];
	for (int i = 0; i < row; i++)
	{
		rsData[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			rsData[i][j] = 0;
		}
	}

	int minRow = (Rows > row) ? row : Rows;
	int minCol = (Columns > col) ? col : Columns;
	int  colSize = minCol * sizeof(float);


	for (int i = 0; i < minRow; i++)
	{
		memcpy(rsData[i], MatData[i], colSize);
	}

	for (int i = 0; i < minRow; i++)
	{
		delete[] MatData[i];
	}
	delete[] MatData;
	MatData = rsData;
	Rows = row;
	Columns = col;
	return;
}
//重载预算符-
Matrix operator - (const Matrix& m1, const Matrix& m2)
{

	if ((m1.Col() != m2.Col()) || (m1.Row() != m2.Row()))
	{
		throw("matrix::operator-: The two matrix have different size!");
	}

	Matrix matTmp(m1.Row(), m1.Col());
	for (int i = 0; i < m1.Row(); i++)
	{
		for (int j = 0; j < m1.Col(); j++)
		{
			matTmp(i, j) = m1(i, j) - m2(i, j);
		}
	}
	return matTmp;
}

//重载预算符*,两个矩阵相乘，m1的列要等于m2的行
Matrix operator * (const Matrix& m1, const Matrix& m2)
{

	if ((m1.Col() != m2.Row()))
	{
		throw("matrix::operator*: The col of matrix m1 doesn't equ to row of m2 !");
	}

	Matrix matTmp(m1.Row(), m2.Col());
	for (int i = 0; i < m1.Row(); i++)
	{
		for (int j = 0; j < m2.Col(); j++)
		{
			for (int k = 0; k < m2.Row(); k++)
			{
				matTmp(i, j) += m1(i, k) * m2(k, j);
			}
		}
	}
	return matTmp;
}

//重载预算符*,矩阵右乘一个数
Matrix operator * (const Matrix& m1, const float& num)
{
	Matrix matTmp(m1.Row(), m1.Col());
	for (int i = 0; i < m1.Row(); i++)
	{
		for (int j = 0; j < m1.Col(); j++)
		{
			matTmp(i, j) = m1(i, j) * num;

		}
	}
	return matTmp;
}

//重载运算符*,矩阵左乘一个数
Matrix operator * (const float& num, const Matrix& m1)
{
	Matrix matTmp(m1.Row(), m1.Col());
	for (int i = 0; i < m1.Row(); i++)
	{
		for (int j = 0; j < m1.Col(); j++)
		{
			matTmp(i, j) = m1(i, j) * num;
		}
	}
	return matTmp;
}
//重载运算符>>，为矩阵元素赋值
istream& operator>>(istream& input, Matrix& m)
{
	int i, j;
	cout << "请输入矩阵:" << endl;
	for (i = 0; i < m.Row(); i++)
	{
		for (j = 0; j < m.Col(); j++)
			input >> m.MatData[i][j];
	}
	return input;
}
//重载运算符<<，直接打印输出矩阵
ostream& operator<<(ostream& output, Matrix& m)
{
	int i, j;
	for (i = 0; i < m.Row(); i++)
	{
		for (j = 0; j < m.Col(); j++)
		{
			if (j == m.Col()-1)
			{
				output << m.MatData[i][j];
				output << endl;
			}
			else
			{
				output << m.MatData[i][j] << " ";
			}
		}
		output << endl;
	}
	return output;
}







