#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	_M = 0;
	_N = 0;
	_data = NULL;
}
Matrix::Matrix(const int N, const int M)
{
	_M = M;
	_N = N;
	_data = new double* [_N];
	for (int i = 0; i < _N; i++)
	{
		_data[i] = new double[_M];
	}
}
Matrix::Matrix(const Matrix& c) 
{
	_N = c._N;
	_M = c._M;
	_data = new double* [_N];
	for (int i = 0; i < _N; i++) 
	{
		_data[i] = new double[_M]();
	}
	for (int i = 0; i < _N; i++) 
	{
		for (int j = 0; j < _M; j++) 
		{
			_data[i][j] = c._data[i][j];
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < _N; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}

Matrix Matrix:: operator = (Matrix c)
{
	for (int i = 0; i < _N; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
	_N = c._N;
	_M = c._M;
	_data = new double* [_N];
	for (int i = 0; i < _N; i++)
	{
		_data[i] = new double[_M];
	}
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _M; j++)
		{
			_data[i][j] = c._data[i][j];
		}
	}
	return c;
}
double& Matrix :: operator() (const int N, const int M)
{
	if (M > _M || N > _N)
	{
		throw std::logic_error("error");// исключение ошибка
	}
	return _data[N][M];
}
Matrix Matrix :: operator +  (const Matrix& c)
{
	if (_M !=c. _M && _N !=c. _N)
	{
		throw std::logic_error("matrices of different sizes cannot be stacked");
	}
	//можно складывать только матрицы одинаковые по размеру
	Matrix res(_N, _M);// размерность
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _M; j++)
		{
			res._data[i][j] = _data[i][j] + c._data[i][j];
		}
	}
	return res;
}
Matrix Matrix :: operator -  (const Matrix& c)
{
	if (c._M != _M && c._N != _N)
	{
		throw std::logic_error("matrices of different sizes cannot be subtracted");
	}
	//можно складывать только матрицы одинаковые по размеру
	Matrix res(_N, _M);
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _M; j++)
		{
			res._data[i][j] = _data[i][j] - c._data[i][j];
		}
	}
	return res;
}
Matrix Matrix :: operator * (const Matrix& c)//нужно ввести размерность ещё?
{
	if (_M != c._N)
	{
		throw std::logic_error("the number of rows of the first matrix is not equal to the number of columns of the second");
	}
	//можно перемножать матрица только если кол-во столбцов 1 матрицы равно кол-ву строк 2
	Matrix res (_N, c._M);// размерность [кол-во строк 1 _M,кол-во столбцов 2]
	
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _M; j++)
		{
			res._data[i][j] = 0;
			for (int k = 0; k < _M; k++)
			{
				res._data[i][j] += _data[i][k] * c._data[k][j];
			}
		}
	}
	return res;
}
Matrix Matrix :: operator * (const double a)
{
	Matrix res(_N, _M);
	for (int i = 0; i < _M; i++)
	{
		for (int j = 0; j < _N; j++)
		{
			res._data[i][j] = _data[i][j] * a;
		}
	}
	return res;
}
Matrix Matrix :: operator / (const double a)
{
	Matrix res(_N, _M);
	for (int i = 0; i < _M; i++)
	{
		for (int j = 0; j < _N; j++)
		{
			res._data[i][j] = _data[i][j] / a;
		}
	}
	return res;
}
//Контроль сравнения вещественных чисел
bool Matrix :: operator == (const Matrix& c)
{
	if (_N == c._N || _M == c._M )
	{
		for (int i = 0; i < _N; i++)
		{
			for (int j = 0; j < _M; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return false;
			}
		}
		return true;
	}	
	return false;
}
bool Matrix :: operator != (const Matrix& c)
{
	if (_N == c._N || _M == c._M )
	{
		for (int i = 0; i < _N; i++)
		{
			for (int j = 0; j < _M; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return true;
			}
		}
		return false;
	}
	return true;
}

double Matrix :: finding_a_trace() const
{
	if (_N != _M)
	{
		throw std::logic_error("error");
	}
	double a = 0;
	for (int i = 0; i < _M; i++)
	{
		a += _data[i][i];
	}
	return a;
}

std::ostream& operator<<(std::ostream& out, const Matrix& a)
{
	if (a._data != NULL) 
	{
		for (int i = 0; i < a._N; i++) 
		{
			for (int j = 0; j < a._M; j++) 
			{
				out << a._data[i][j] << " ";
			}
			out << std::endl;
		}
		return out;
	}
	else 
	{
		out << "Matrix does not exist";
	}
}
std::istream& operator>>(std::istream& in, Matrix& a)
{
	for (int i = 0; i < a._N; i++) 
	{
		for (int j = 0; j < a._M; j++) 
		{
			std::cout << "[" << i << "][" << j << "] - ";
			in >> a._data[i][j];
		}
	}
	return in;
}