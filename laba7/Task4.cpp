// laba7 task4
// 
//  Осуществить сложение и вычитание чисел в заданной системе 
//  счисления.В другую систему счисления не переводить.В системах
//  счисления больших десятичной использовать буквы по аналогии с
//  шестнадцатеричной системой.Разработать функции для выполнения
//  операции сложения и функции для выполнения операции вычитания.
//  Предусмотреть ввод положительных и отрицательных чисел.
//
//  5) в одиннадцатеричной;

#include <iostream>
#include <string>

using namespace std;

int GetSize(string s) {
    int size = 0;

    while (s[size] != '\0')
        size++;
    return size;
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

string GetNumber()
{
    string str;
    bool isNumber;

    do {
        isNumber = true;
        cin >> str;
        for (int i = 0; i < GetSize(str); i++) {
            if (!isdigit(str[i]) && !(str[i] == '-') && !(str[i] == 'A')) {
                 cout << "\nНекорректный ввод. Попробуйте ещё раз.\n";
                 isNumber = false;
                 break;        
            }
        }
    } while (!isNumber);

    return str;
}


char GetOperation()
{
    string sign;
    bool isOperation = true;

    do {
        isOperation = true;
        cin >> sign;
        for (int i = 0; i < GetSize(sign); i++) {
            if ((sign[i] != '+' && sign[i] != '-') || i > 0) {
                isOperation = false;
                cout << "Некорректная оперция. Выберите '+' или '-'\n";
                break;
            }
        }

    } while (!isOperation);

    return sign[0];
}

void myErase(string& str, const int& start)  // удаляет один элемент
{
    int tmp, size = GetSize(str);

    for (int i = start; i < size; i++) {
        tmp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tmp;
    }
}


int action(string& num1, string& num2, char& operation)
{
    if ((((num1[0] == '-' && num2[0] == '-') || (num1[0] == '+' && num2[0] == '+')) && operation == '+') || ((num1[0] == '+' && num2[0] == '-') && operation == '-')) return 1;
    return 0;   //  Возращает true если выполняется сумма, false в противном случае
}

string sum(string& num1, string& num2)
{
    string result;
    char sign = ' ';
    if (num1[0] == '-') {
        sign = '-';
        myErase(num1, 0);
        myErase(num2, 0);
    }
    if (num2[0] == '-') myErase(num2, 0);
    string ls1 = GetSize(num1) < GetSize(num2) ? num1 : num2; //little string
    string ls2 = GetSize(num1) < GetSize(num2) ? num2 : num1;                   //equalize strings
    if (GetSize(num1) != GetSize(num2)) {
        for (int i = GetSize(ls1); i < GetSize(ls2); i++) ls1 = '0' + ls1;
    }
    int a = 0, b = 0, f = 0;  //f - remainder
    for (int i = GetSize(ls1) - 1; i >= 0; i--) {
        if (ls1[i] == 'A') a = 10;
        else a = (int)ls1[i] - 48; //convert to digit
        if (ls2[i] == 'A') b = 10;
        else b = (int)ls2[i] - 48;
        if ((a + b + f) % 11 == 10) result = 'A' + result;
        else result = (char)(((a + b + f) % 11) + 48) + result;
        f = (a + b + f) / 11;
    }
    return sign + result;
}

string substr(string& num1, string& num2)
{
    if (num1[0] == '-') myErase(num1, 0);
    if (num2[0] == '-') myErase(num2, 0);
    string result;
    int len1 = GetSize(num1);
    int len2 = GetSize(num2);
    string ls1 = len1 < len2 ? num1 : num2;  //smaller str
    string ls2 = len1 < len2 ? num2 : num1;  //bigger str         //equalize strings
    if (len1 != len2) {
        for (int i = GetSize(ls1); i < GetSize(ls2); i++) ls1 = '0' + ls1;   //add zeros
    }
    int counter = 0;
    char sign = ' ';
    if (StringToInteger(num1) - StringToInteger(num2) < 0) sign = '-'; //check sign of result
    while (counter < GetSize(ls1)) {
        if ((int)ls1[counter] < (int)ls2[counter]) {
            swap(ls1, ls2);
            break;       //find greatest |number| and assign it first
        }
        counter++;
    }
    string tmp1, tmp2;
    int a = 0, b = 0, f = 0;  //f - remainder
    for (int i = 0; i < GetSize(ls2); i++) {
        tmp1 = ls1[GetSize(ls1) - 1 - i];
        tmp2 = ls2[GetSize(ls2) - 1 - i];
        if (tmp1[0] == 'A') a = 10 - f;
        else a = StringToInteger(tmp1) - f;
        if (tmp2[0] == 'A') b = 10;
        else b = StringToInteger(tmp2);
        if (a - b < 0) {
            a += 11;
            f = 1;
        }
        else f = 0;
        if (a - b == 10) result = 'A' + result;
        else result = (char)(a - b + 48) + result;
    }
    if (f != 0) result = (char)(f + 48) + result;
    if (result[0] == 0) myErase(result, 0);
    return sign + result;
}


int main()
{
    setlocale(LC_ALL, "rus");
    string str1, str2;

    cout << "Программа реализует сложение в одиннацеричной системе счисления\n";
    cout << "Выберите операцию '+' или '-':\n";

    char operation = GetOperation();
    cout << "Первое число:   ";
    str1 = GetNumber();

    cout << "Второе число:   ";
    str2 = GetNumber();

    if (action(str1, str2, operation)) cout << "Результат:   " << sum(str1, str2);
    else cout << "Результат:   " << substr(str1, str2);

    return 0;
}