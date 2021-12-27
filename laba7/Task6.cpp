// Lab7 Task6 
//  Пусть S(x) - это сумма цифр числа х, записанного в десятичной системе счисления.
//  Например, S(5) = 5, S(10) = 1, S(322) = 7
//  Будем называть число х интересным, если S(x + 1) < S(х). В каждом тесте будет дано одно число n.
//  Ваша задача посчитать кол-во чисел х таких, что 1 <= x <= n и х - интересное 

#include <iostream>

using namespace std;

int main()
{
    int t, num;

    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {

        cout << "Enter n: ";
        cin >> num;

        cout << "Number of \"interesting\" numbers: " << (num + 1) / 10 << '\n';
    }

    return 0;
}