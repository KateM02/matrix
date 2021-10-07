
#include "Matrix.h"
#include <iostream>
#include <stdio.h>
#include<conio.h>


int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) 
		key = _getch();
	return key;
}

Matrix input_values()
{
	int N = 0, M = 0;
	do
	{
		std::cout << "Input N:";
		std::cin >> N;
	} while (N <= 0);
	do
	{
		std::cout << "Input M:";
		std::cin >> M;
	} while (N <= 0);
	std::cout << "Input values:\n";
	Matrix a(N, M);
	std::cin >> a;
	std::cout << a;
	return a;
}
int menu()
{
	while (true)
	{
		std::cout << "\n1.Input matrix" << std::endl << "2.Perform math operations" << std::endl << "3.Exit\n";
		int key = get_key();
		if (key >= 49 && key <= 51)
			return key;
	}
}
int menu_matematical_operation()
{
	while (true)
	{
		std::cout << "\n1.matrix addition\n" << "2.subtraction of matrices\n"<< "3.matrix multiplication\n" << "4.multiplication by a number\n" << "5.division by number\n" << "6.Comparison of matrices\n" <<"7.index appeal\n"<< "8.finding the trace of a matrix\n";
		int key = get_key();
		if (key >= 49 && key <= 56)
			return key;
	}
	
}
void matematical_operation(Matrix a)
{
	try
	{
		Matrix b;
		int choose = menu_matematical_operation();
		switch (choose)
		{
		case '1':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a + b;
		}
		break;
		case '2':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a - b;

		}
		break;
		case '3':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a * b;
		}
		break;
		case '4':
		{
			double c;
			std::cout << "Input the number:";
			std::cin >> c;
			std::cout << "Result:" << std::endl << a * c << std::endl;
		}
		break;
		case '5':
		{
			double c;
			std::cout << "Input the number:";
			std::cin >> c;
			std::cout << "Result:" << std::endl << a / c << std::endl;
		}
		break;
		case '6':
		{
			b = input_values();
			if (a == b)
			{
				std::cout << "Matrices are equal";
			}
			if (a != b)
			{
				std::cout << "Matrices are not equal";
			}
		}
		break;
		case '7':
		{
			std::cout << "Enter which element of the matrix you want to find\n";
			int x, y;
			std::cout << "Input x";
			std::cin >> x;
			std::cout << "Input y";
			std::cin >> y;
			std::cout << "Result:" << a(x, y) << std::endl;

		}
		break;
		case '8':
		{
			double c = a.finding_a_trace();
			std::cout << "Result:" << c << std::endl;
		}
		break;
		default:
			break;
		}
	}
	catch(std::exception err)
	{
		std::cerr << "Caught: " << err.what() << std::endl;
	}
	
}

int main()
{
	Matrix a;
	bool f = true;
	while (f)
	{
		int choose = menu();
		switch (choose)
		{
		case '1':
		{
			a = input_values();
		}
		break;
		case '2':
		{
			matematical_operation(a);
		}
		break;
		case '3':
		{
			f = false;
		}
		default:
			break;
		}
	}
	return 0;
}