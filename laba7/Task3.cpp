// laba7 task3
//  Осуществить сложение чисел.Разработать функции для
//  выполнения операции сложения.Предусмотреть ввод положительных и
//  отрицательных чисел.
//
//  5. Найдите сумму двоичных чисел, заданных в естественной 
//  форме.Сложение выполните в дополнительном коде.Ответ
//  выразите в прямом коде.


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int GetSize(string s);
int GetInt();
int StringToInteger(string str);
string ConvertDecToBin(int number);
string ConvertStrToAdd(string& number);
string Sum(const string& num1, const string& num2);

int main()
{
    int num1, num2;
    
    setlocale(LC_ALL, "rus");

    cout << "Эта программа считает сумму двух чисел в естественной форме в дополнительном коде\n";
    cout << "Введите два числа в естественной форме\n";

    cout << "Первое число:   ";
    num1 = GetInt();

    cout << "Второе число:   ";
    num2 = GetInt();

    string str1 = ConvertDecToBin(num1), str2 = ConvertDecToBin(num2);

    cout << '\n' << str1 << "    " << str2 << "    -   числа в двоичном коде\n\n";
    cout << ConvertStrToAdd(str1) << "    " << ConvertStrToAdd(str2) << "   -    числа в дополнительном коде\n\n";
    
    cout << "Сумма чисел:   " << Sum(str1, str2);

    return 0;
}

int GetSize(string s) {
    int size = 0;

    while (s[size] != '\0')
        size++;
    return size;
}

int GetInt() {
    string str;
    bool isInteger;

    do {
        isInteger = true;
        cin >> str;
        for (int i = 0; i < GetSize(str); i++) {
            if (!isdigit(str[i]) && !(str[i] == '-')) {
                cout << "\nНекорректный ввод. Попробуйте ещё раз.\n";
                isInteger = false;
                break;
            }
        }
    } while (!isInteger);

    return StringToInteger(str);
}

int StringToInteger(string str) {
    int ans = 0, sign = 1, size = GetSize(str);

    if (str[0] == '-') sign = -1;

    for (int i = 0; i < size; i++) {
        if (str[i] != '-') {
            ans += ((str[i]) - '0') * pow(10, size - 1 - i);
        }
    }
    return sign * ans;
}

string ConvertDecToBin(int number) {        //  перевод из десятичного в двочное число
    char sign = '0';
    if (number < 0) sign = '1';

    string result;
    int copyOfNum = abs(number);

    while (copyOfNum != 0) {
        result += ((copyOfNum % 2) + '0');
        copyOfNum /= 2;
    }

    int size = GetSize(result);

    copyOfNum = abs(number);

    char tmp;
    for (int i = 0; i < size / 2; i++) {
        tmp = result[i];
        result[i] = result[size - i - 1];
        result[size - i - 1] = tmp;
    }

    int bit = 4;  // Дополняем число нулями спереди до размера степени двойки
    if (copyOfNum >= 7 && copyOfNum <= 127) {
        bit = 8;
    }
    else if (copyOfNum > 127 && copyOfNum < 32767) {
        bit = 16;
    }
    else if (copyOfNum >= 32767 && copyOfNum < pow(2, 30)) {
        bit = 32;
    }

    if ((size + 1) % bit != 0) {
        for (int i = 0; i < bit - size - 1; i++) {
            result = '0' + result;
        }
    }

    return sign + result;
}

string ConvertStrToAdd(string& number) {     // Перевод двоичного числа в дополнительный код
    int size = GetSize(number);

    if (number[0] == '1') {
        for (int i = 1; i < size; i++)
        {
            if (number[i] == '1')
                number[i] = '0';
            else
                number[i] = '1';
        }
        for (int i = size - 1; i > 0; i--)
        {
            if (number[i] == '1') {
                number[i] = '0';
            }
            else {
                number[i] = '1';
                break;
            }
        }
    }

    return number;
}

string Sum(const string& num1, const string& num2) {  // Сумма в дополнительном коде
    string result;

    int size1 = GetSize(num1), size2 = GetSize(num2);
    string shStr, longStr;

    if (size1 <= size2) {
        shStr = num1;
        longStr = num2;
    }
    else {
        shStr = num2;
        longStr = num1;
    }

    if (size1 != size2) {
        char sign1 = shStr[0];
        shStr[0] = '0';

        for (int i = GetSize(shStr); i < GetSize(longStr) - 1; i++) {
            shStr = '0' + shStr;
        }

        shStr = sign1 + shStr;
    }

    char tmp = '0';
    for (int i = shStr.size() - 1; i >= 0; i--) {
        if (shStr[i] == '0' && longStr[i] == '0') {
            result = tmp + result;
            tmp = '0';
        }

        if ((shStr[i] == '1' && longStr[i] == '0') || (shStr[i] == '0' && longStr[i] == '1')) {
            if (tmp == '1') {
                result = '0' + result;
                tmp = '1';
            }
            else {
                result = '1' + result;
                tmp = '0';
            }
        }
        if (shStr[i] == '1' && longStr[i] == '1') {
            result = tmp + result;
            tmp = '1';
        }

    }
    return ConvertStrToAdd(result);
}
