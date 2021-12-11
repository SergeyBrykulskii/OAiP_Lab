// Exercise 3, additional task 2  
//  This program take matrix of real numbers and determines whether there are elements with zero value in matrix.
//  If there are such elements, then determines their indicesand the total number. Rearranges the elements of this
//  matrix in reverse orderand prints to the screen.

#include <iostream>
#include <vector>
#include "StaticLib2.0.h"

using namespace std;

int main()
{
    int width, length, sum = 0;
    cout << "Enter size of array(width, length): ";

    width = GetNaturalNumber();
    length = GetNaturalNumber();

    vector<vector<double>> matrix = GetMatrixOfReal(width, length);
    
    FindZeroInMatrix(matrix, width, length, sum);

    if (sum)
        cout << "\nThe total number of zero elements of the matrix: " << sum << '\n';
    else
        cout << "There aren't zero elements in the matrix\n";

    ReverseMatrix(matrix, width);

    cout << "Reversed original matrix:\n";

    PrintMatrixOfReal(matrix);

    return 0;
}