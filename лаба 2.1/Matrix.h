#pragma once
#include <utility>
#include <iostream>

class Matrix
{
private:
	int _N;// строки
	int _M;//столбцы
	double** _data;//значение для заполнения?
public:
	Matrix();
	Matrix(const int M,const int N);
	Matrix(const Matrix& c);// конструктор копирования
	~Matrix();
	double& operator () (const int M, const int N);
	Matrix operator = (Matrix c);
	Matrix operator + (const Matrix& c);
	Matrix operator - (const Matrix& c);
	Matrix operator * (const Matrix& c);
	Matrix operator * (const double a);
	Matrix operator / (const double a);
	bool operator == (const Matrix& c);
	bool operator != (const Matrix& c);
	double finding_a_trace() const;

	friend std::ostream& operator<<(std::ostream& out, const Matrix& a);
	friend std::istream& operator>>(std::istream& in, Matrix& lhs);
};

