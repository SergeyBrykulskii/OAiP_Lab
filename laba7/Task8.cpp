// laba7 task8

#include <iostream>
#include <string>

using namespace std;

int GetSize(string s);
long long int StringToInteger(string str);
string  ConvertToBin(const string& number);
string BinCounter(const int& end);
int GetInt();


int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Программа ищет двудесятичные числа\nВведите номер двудесятичного числа:\t";
    int test;
    test = GetInt();

    cout << BinCounter(test) << endl;

    return 0;
}


int GetSize(string s) {
    int size = 0;

    while (s[size] != '\0')
        size++;
    return size;
}

long long int StringToInteger(string str) {
    long long int ans = 0, sign = 1, size = GetSize(str);

    if (str[0] == '-') sign = -1;

    for (int i = 0; i < size; i++) {
        if (str[i] != '-') {
            ans += ((str[i]) - '0') * pow(10, size - 1 - i);
        }
    }
    return sign * ans;
}

string  ConvertToBin(const string& number) {
    long long int tmp = StringToInteger(number);
    string ans;

    while (tmp != 0) {
        ans = char((tmp % 2) + 48) + ans;
        tmp /= 2;
    }
    return ans;
}

string BinCounter(const int& end) {
    string ans = "0", tmp;
    int counter = 0, i = 0;

    while (i < end) {   //  пока мы не найдём нужный номер
        if (ans[GetSize(ans) - 1] == '0') ans[GetSize(ans) - 1] = '1';
        else {
            counter = 0;
            while (counter < GetSize(ans)) {
                if (ans[GetSize(ans) - 1 - counter] == '0') {
                    ans[GetSize(ans) - 1 - counter] = '1';

                    for (int k = GetSize(ans) - counter; k < GetSize(ans); k++) {
                        ans[k] = '0';
                    }
                    break;
                }
                counter++;
            }
            if (counter == GetSize(ans)) {
                for (int j = 0; j < GetSize(ans); j++) {
                    ans[j] = '0';
                }
                ans = '1' + ans;
            }
        }
        tmp = ConvertToBin(ans);      //перевод в двоичное число
        tmp = tmp.substr(GetSize(tmp) - GetSize(ans), GetSize(tmp));

        if (ans == tmp) {    // если они одинаковые добавляем единицу
            i++;
        }
    }
    return ans;
}

int GetInt() {
    string str;
    bool isInteger;

    do {
        isInteger = true;
        cin >> str;
        for (int i = 0; i < GetSize(str); i++) {
            if (!isdigit(str[i])) {
                cout << "\nНекорректный ввод. Попробуйте ещё раз.\n";
                isInteger = false;
                break;
            }
        }
    } while (!isInteger);

    return StringToInteger(str);
}
