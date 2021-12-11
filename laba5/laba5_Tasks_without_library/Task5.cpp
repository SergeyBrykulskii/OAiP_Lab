// Additional task 2

#include<iostream>
#include<cmath>
#include "StaticLib2.0.h"

using namespace std;

unsigned long long Take_modulo(const unsigned long long& k, const unsigned long long& n, const unsigned long long& t);

int main()
{
    unsigned long long k, n, t;
    cout << "Enter k, n, t: ";

    while ((k = GetNaturalNumber()) && (n = GetNaturalNumber()) && (t = GetNaturalNumber())) {
        if (!k && !n && !t) {
            cout << "\nProgram completed successfully!\n";
            return 0;
        }

        t = pow(10, t);

        cout << Take_modulo(k % t, n, t) << "\n\nEnter k, n, t: ";
    }

    return 0;
}


unsigned long long Take_modulo(const unsigned long long& k, const unsigned long long& n, const unsigned long long& t) {
    if (!n) {
        return 1;
    }
    if (n % 2 == 1) {
        return (k * Take_modulo((k * k) % t, n / 2, t)) % t;
    }
    return Take_modulo((k * k) % t, n / 2, t);

}