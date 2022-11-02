// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Func.hpp"


int main()
{

        std::cout << "Hello World!\n";
        int i = 0;
        int j = 0;
        mt::Frand(i);
        mt::Frand(j);
        int** A = new int* [i];
        for (int m = 0; m < i; m++)
        {
            A[m] = new int[j];
        }
        int x = 0;
        double* y = new double[j];
        bool ar = false;
        mt::matrx(A, i, j);
        mt::array(ar, A, i, j);
        if (ar)
        {

            for (int n = 0; n < j; n++)
            {
                for (int m = 0; m < i; m++)
                {
                    x += A[m][n] * A[m][n];
                }
                y[n] = sqrt(x);
            }
            for (int n = 0; n < j; n++)
            {
                for (int m = n; m < j; m++)
                {
                    if (y[n] < y[m])
                    {
                        std::swap(y[n], y[m]);
                        std::swap(A[i][n], A[i][m]);
                    }
                }
            }
            for (int m = 0; m < i; m++)
            {
                for (int n = 0; n < j; n++)
                {
                    std::cout << "[" << A[m][n] << "] ";
                }
                std::cout << "\n";
            }
            for (int n = 0; n < j; n++)
            {
                std::cout << " " << y[n] << "  ";
            }
        }
        else
            std::cout << "answer not found" << std::endl;
        delete[] A;
        delete[] y;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
