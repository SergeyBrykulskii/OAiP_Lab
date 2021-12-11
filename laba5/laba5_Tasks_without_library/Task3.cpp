// Exercise 3, additional task 3  
// This program accepts a dynamic array of integers. Create a dynamic array from elements,
// located in even columns of this arrayand having an odd value.
// Calculate the arithmetic mean of the elements of a dynamic array.

#include <iostream>
#include <vector>
#include <StaticLib2.0.h>

using namespace std;

int main()
{
    int width, length;

    cout << "Enter size of array(width, length): ";
    
    width = GetNaturalNumber();
    length = GetNaturalNumber();

    vector<int> array = MakeArray(GetMatrixOfInt(width, length), width, length);

    cout << "New array:\n";

    PrintArrayOFInt(array);

    cout << "\nThe average of this array: " << CountAverageOfArray(array) << '\n';

    return 0;
}