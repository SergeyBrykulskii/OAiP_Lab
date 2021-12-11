#include <iostream>

#include "number.h"

using namespace std;

// Variant 6
int main() {
    string s;
    cout << "Enter a 5-based number to convert it to 14-based: ";
    cin >> s;
    Number num(s, 5);
    int decimal = 0;
    for (auto i : s) {
        if (i == '-') {
            continue;
        }
        decimal *= 5;
        decimal += static_cast<int>(i - '0');
    }
    string res = "";
    while (decimal) {
        if (decimal % 14 > 9) {
            res += static_cast<char>('A' + decimal % 14 - 10);
        }
        else {
            res += static_cast<char>('0' + decimal % 14);
        }
        decimal /= 14;
    }
    reverse(res.begin(), res.end());
    if (s[0] == '-') {
        res.insert(res.begin(), '-');
    }
    cout << "Using arrays: " << Number(num, 14).getString()
        << " without arrays: " << res << endl;
    return 0;
}