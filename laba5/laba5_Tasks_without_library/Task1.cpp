// Exercise 3, additional task 1  
// This program takes a matrix of integer number with size (5, 6), find even numbers on diagonal of this matrix and push it to array
// aslo it count product of new array elements

#include <iostream>
#include <vector>
#include "StaticLib2.0.h"

using namespace std;

int main()
{
    int width = 5, length = 6;
    cout << "The size of array(width, length): (5, 6)\n\n";

    cout << "Prodact of even elements from diagonal:  " << CountProductOfArray(FindEvenFromDiagonal(GetMatrixOfInt(width, length), width, length)) << '\n';

    return 0;
}