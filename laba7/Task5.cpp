//  laba7 task5
//  Перевести число из арабской системы записи чисел в римскую.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string ans_num = "";
    string roman_numbers[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int roman_in_arabian[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    cout << "Enter arabian number to convert it to roman number: ";
    cin >> num;
    
    for (int i = 12; i >= 0; i--)
    {
        while (num - roman_in_arabian[i] >= 0) {
            ans_num += roman_numbers[i];
            num -= roman_in_arabian[i];
        }
    }

    cout << "\nNumber in roman numeral: " << ans_num << '\n';

    return 0;
}
