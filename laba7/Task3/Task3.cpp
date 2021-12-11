#include <iostream>

using namespace std;


int main() {
    int a = 3;
    int b = 4;
    int c = 6;
    //int &d = b;

    a = b = c;

    cout << a << b << c;
    return 0;
}