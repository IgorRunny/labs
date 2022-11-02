#include "Func.hpp"
#include <iostream>
namespace mt
{
	int Frand(int x)
	{
		bool t;
		x = rand() % 100 + 1;
		t = rand() % 2;
		if (t)
			x = x * (-1);
		return x;
	}

	bool simple(int x)
	{
		bool s;
		for (int i = 2; i < sqrt(x); i++)
		{
			if (x % i == 0)
			{
				s = false;
				break;
			}
			else
				s = true;
		}
		return s;
	}

	bool array(bool ar, int** X, int i, int j)
	{
		bool s = false;
		int sum = 0;
		for (int m = 0; m < i; m++)

		{
			for (int n = 0; n < j; n++)
			{
				sum += X[m][n];
				if (simple(X[m][n]))
				{
					s = true;
				}
			}
			if (s = true, sum == 0)
			{
				ar = true;
				break;
			}
		}
		return ar;
	}

	void matrx(int** X, int i, int j)
	{
		for (int m = 0; m < i; m++)
		{
			for (int n = 0; n < j; n++)
			{
				mt::Frand(X[m][n]);
			}
		}
	}
}