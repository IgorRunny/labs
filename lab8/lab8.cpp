// lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    long long b = 8929092027351663717LL;

    for (int i = 0; i < sizeof(long long); i++)
        printf("%d ", *(((unsigned char*)&b) + i));//printf - функция вывода, которая позволяет выводить информацию в разном формате, в зависиости от спецификаторов
    //спецификатор "%d" нужен, чтобы выводить десятичные целые числа
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
