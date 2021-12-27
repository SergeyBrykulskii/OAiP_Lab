// laba7 task9


#include <iostream>

using namespace std;

int main()
{
    int a;
    string ans = "";

    cin >> a;

    while (a) {
        if (a % 3 == 0) {
            ans = '3' + ans;
            a = (a - 1) / 3;
        }
        else {
            char ch = (a % 3) + '0';
            ans = ch + ans;
            a /= 3;
        }
    }

    cout << ans << '\n';
    return 0;
}
