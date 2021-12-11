// Additional task 2

#include<iostream>
#include<cmath>
#include "StaticLib2.0.h"

using namespace std;

unsigned long long CountNumberOfDivisors(const int &num);

int main()
{
    int num;
    cout << "Enter number(enter 0 to ends the program): ";

    while (num = GetNaturalNumber()) {
        if (num == 0) {
            cout << "\nProgram completed successfully!\n";
            return 0;
        }

        cout << "Required amount: " << CountNumberOfDivisors(num) << "\n\nEnter number(enter 0 to ends the program): ";
    }

    return 0;
}


unsigned long long CountNumberOfDivisors(const int &num) {

    if (!num) {
        return 0;
    }
  
    return (((num + 1) / 2) * ((num + 1) / 2)) + CountNumberOfDivisors(num / 2);
}