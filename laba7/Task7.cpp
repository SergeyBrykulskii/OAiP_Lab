#include <iostream>

using namespace std;

int Add(int num1, int num2);
int Negative(int& n);
int Subtraction(int a, int b);

int main()
{
    setlocale(LC_ALL, "rus");
    int a, tmp, arr[3] = { 5, 73, 151 };

    cout << "Программа проверяет делится ли число на 5, 72, 151.\n Введите число, которое вы хотите проверить:\t";
    cin >> a;

    for (int i = 0; i < 3; i++) {
        tmp = abs(a);

        while (tmp > 0) {
            tmp = Subtraction(tmp, arr[i]);
        }

        if (tmp == 0) {
            cout << a << " делится на " << arr[i] << "\n";
        }
        else {
            cout << a << " не делится на " << arr[i] << "\n";
        }
    }

    return 0;
}

int Add(int num1, int num2) {
    int res = 0, carry = 0;
    res = num1 ^ num2;
    carry = (num1 & num2) << 1;
    while (carry) {
        int tmp = res;
        res ^= carry;
        carry = (tmp & carry) << 1;
    }
    return res;
}

int Negative(int& n) {
    n = ~n;
    return Add(n, 1);
}

int Subtraction(int a, int b) {
    return Add(a, Negative(b));
}