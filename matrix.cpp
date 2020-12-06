
#include "matrix.h"
#include <cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>

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

Matrix::~Matrix(void)//�������У������ڴ汻�ظ��ͷ�
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

//��������Ԫ�أ����÷��أ�
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


//���������+
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


//����ǳ��������������Ԫ��ָ��ָ��ͬһ���ڴ�ռ�
Matrix& Matrix::operator = (const Matrix& m)
{

	this->Columns = m.Columns;
	this->Rows = m.Rows;
	this->MatData = m.MatData;
	return *this;


}


//���������С��ԭ��ֵ����
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
//����Ԥ���-
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

//����Ԥ���*,����������ˣ�m1����Ҫ����m2����
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

//����Ԥ���*,�����ҳ�һ����
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

//���������*,�������һ����
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
//���������>>��Ϊ����Ԫ�ظ�ֵ
istream& operator>>(istream& input, Matrix& m)
{
	int i, j;
	cout << "���������:" << endl;
	for (i = 0; i < m.Row(); i++)
	{
		for (j = 0; j < m.Col(); j++)
			input >> m.MatData[i][j];
	}
	return input;
}
//���������<<��ֱ�Ӵ�ӡ�������
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







