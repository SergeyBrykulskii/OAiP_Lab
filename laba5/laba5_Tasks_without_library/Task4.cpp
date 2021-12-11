// Additional task 1
// This program implements a recursive function
// Processes requests until two negative numbers are entered

#include <iostream>
#include <vector>
#include "StaticLib2.0.h"

using namespace std;

int main()
{
    int start, finish, sum = 0;
    cout << "Enter start and end position of the sum(enter two negative numbers, when you want to end the program): ";
    while ((start = GetIntegerNumber()) && (finish = GetIntegerNumber())) {
        sum = 0;
        if (start < 0 && finish < 0) {
            cout << "\nProgram completed successfully!\n";
            return 0;
        }
        else if (start < 0) {
            cout << "Start position must be positive number(enter two negative numbers, when you want to end the program)";
            cout << "Enter start and end position of the sum(enter two negative numbers, when you want to end the program): ";
            start = GetIntegerNumber(); 
            finish = GetIntegerNumber();
        }
        else if (finish < 0) {
            cout << "End position must be positive number(enter two negative numbers, when you want to end the program)";
            cout << "Enter start and end position of the sum(enter two negative numbers, when you want to end the program): ";
            start = GetIntegerNumber(); 
            finish = GetIntegerNumber();
        }

        for (int i = start; i <= finish; i++) {
            sum += RecursionForFirstTask(i);
        }

        cout << "\nSum of results from functions: " << sum << "\n\n";

        cout << "Enter start and end position of the sum(enter two negative numbers, when you want to end the program): ";
    }
    


    return 0;
}
