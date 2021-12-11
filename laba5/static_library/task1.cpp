#include <iostream>
#include "my_library.h"

using namespace std;

int main()
{
    int a, b;
    cout << "Enter the size of first vector: ";
    cin >> a;
    cout << "Enter the size of second vector: ";
    cin >> b;
    
    cout << "Maximum element of new matrix: " << FindMaximum(GetVector(a), GetVector(b), a, b) << '\n';

    return 0;
}

