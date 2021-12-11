// laba7 task1

//  Необходимо разработать программу для перевода чисел из 
//  одной системы счисления в другую.
// 
//  5) из тринадцатеричной в троичную;

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    stringstream ss;
    string number;
    double magic;

    cin >> number;

    ss.clear();
    ss << number;
    ss >> magic;

    cout << magic << "\n\n" <<  ;
    return 0;
}
