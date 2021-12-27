// laba7 task1

//  Необходимо разработать программу для перевода чисел из 
//  одной системы счисления в другую.
// 
//  5) из тринадцатеричной в троичную;

#include <iostream>
#include <string>

using namespace std;

int GetSize(string& s);

int main()
{
    string int_number_13 = "", double_number_13 = "", number_13, int_number_3 = "", double_number_3 = "";
    int int_number_10 = 0, digit = 0, start = 0, sign = 1;
    double double_number_10 = 0;
    bool flag = 0;

    cin >> number_13;

    int length = GetSize(number_13);

    if (number_13[0] == '-') {
        sign = -1;
        start = 1;
    }
    
    for (int i = start; i < length; i++)
    {
        if (flag) {
            double_number_13 += number_13[i];
        }
        if (number_13[i] == '.')
            flag = 1;
        if (!flag) {
            int_number_13 += number_13[i];
        }
    }
    //  for integer part of number
    length = GetSize(int_number_13);

    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        if (isdigit(int_number_13[i]))
            digit = int_number_13[i] - '0';
        else {
            if (int_number_13[i] == 'A')
                digit = 10;
            if (int_number_13[i] == 'B')
                digit = 11;
            if (int_number_13[i] == 'C')
                digit = 12;
        }
        int_number_10 += (digit * pow(13, j));
    }

    do {
        int_number_3 = char(int_number_10 % 3 + 48) + int_number_3;
    } while (int_number_10 /= 3);

    if (sign == -1) {
        int_number_3 = '-' + int_number_3;
    }

    //  for fractional part of the number
    length = GetSize(double_number_13);

    for (int i = 0; i < length; i++)
    {
        if (isdigit(double_number_13[i]))
            digit = double_number_13[i] - '0';
        else {
            if (double_number_13[i] == 'A')
                digit = 10;
            if (double_number_13[i] == 'B')
                digit = 11;
            if (double_number_13[i] == 'C')
                digit = 12;
        }
        double_number_10 += (digit * pow(13, -(i + 1)));
    }

    cout << double_number_10 <<"\n\n";
    for (int i = 0; i < 8; i++)
    {
        double_number_3 += char(int(double_number_10 *= 3) + 48);
        double_number_10 -= int(double_number_10);
    }

    cout << int_number_3 << '.' << double_number_3 << '\n';

    return 0;
}

int GetSize(string& s) {
    int size = 0;

    while (s[size] != '\0')
        size++;
    return size;
}
