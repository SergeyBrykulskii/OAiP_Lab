// laba7 task9


#include <iostream>

using namespace std;

int GetSize(string s);
int StringToInteger(string str);
int GetInt();

int main()
{
    setlocale(LC_ALL, "rus");

    int a;
    string ans = "";
    cout << "Введите число, которое вы хотите перевести:\t";
    a = GetInt();

    while (a) {                    //  программа реализует перевод в троичную систему без нуля
        if (a % 3 == 0) {          //  переводим как и в обычную троичную, но когда остаток 0 заменяем на 3
            ans = '3' + ans;       //  а далее работаем числом уменьшенным на 1(алгоритм выведен на листочке, методом атематической интуиции)) )
            a = (a - 1) / 3;
        }
        else {
            char ch = (a % 3) + '0';
            ans = ch + ans;
            a /= 3;
        }
    }

    cout << "Результат перевода:\t" << ans << '\n';

    return 0;
}

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
