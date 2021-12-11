//  Lab №6, task 9
/*В заданной строке, состоящей из букв, цифр и прочих символов, найдите
    сумму всех чисел*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num, sum = 0;
    string s;
    
    cout << "Enter a string from which the program will calculate the sum of numbers:\n";
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            for (int j = 0; i >= 0; i--, j++) {
                if (isdigit(s[i])) {
                    sum += ((s[i] - 48) * pow(10, j));
                    cout << i << " " << sum << '\n';
                }
                else {
                    break;
                }
            }
        }
    }

    cout << "Sum of numbers from the string: " << sum << '\n';

    return 0;
}