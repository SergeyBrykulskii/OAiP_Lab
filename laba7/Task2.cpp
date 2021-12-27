// laba7 task2
//  Перевести числа. Предусмотреть ввод положительных и 
//  отрицательных чисел
// 
//  5. Из прямого кода в дополнительный 

#include <iostream>

#include <string>

using namespace std;

int GetSize(string& s); 

int main() {
    string code_of_number;

    cout << "Enter binary number in signed magnitude representation:\n";
    cin >> code_of_number;
    
    int length = GetSize(code_of_number);

    if (code_of_number[0] == '1') {
        for (int i = 1; i < length; i++)
        {
            if (code_of_number[i] == '1')
                code_of_number[i] = '0';
            else
                code_of_number[i] = '1';
        }
        for (int i = length - 1; i > 0; i--)
        {
            if (code_of_number[i] == '1') {
                code_of_number[i] = '0';
            }
            else {
                code_of_number[i] = '1';
                break;
            }
        }
    }

    cout << "Number in \"twos complement\" code:\n" << code_of_number << '\n';

    return 0;
}

int GetSize(string& s) {
    int size = 0;

    while (s[size] != '\0')
        size++;
    return size;
}