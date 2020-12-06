
#pragma once
#include<iostream>

using namespace std;
class Matrix
{
private:
	int Rows;//�������
	int Columns;//�������
	float** MatData;//�������Ԫ�����ݵĶ�ά����

public:
	Matrix(int row = 3, int col = 3);

	Matrix(const Matrix& m);

	~Matrix(void);

	int Row() const { return Rows; }//������
	int Col() const { return Columns; }//������
	void SetSize(int row, int col);//��������Ĵ�С

	float& operator () (int row, int col);//��ȡ����Ԫ��
	float  operator () (int row, int col) const;//���ػ�ȡ����Ԫ�غ�����ֻ��const�����ܷ���
	Matrix& operator = (const Matrix& m);

	
	friend Matrix operator + (const Matrix& m1, const Matrix& m2);
	friend Matrix operator - (const Matrix& m1, const Matrix& m2);
	friend Matrix operator * (const Matrix& m1, const Matrix& m2);
	friend Matrix operator * (const float& num, const Matrix& m1);
	friend Matrix operator * (const Matrix& m1, const float& num);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream &operator<<(ostream&, Matrix&);
	
	
};






