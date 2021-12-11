//  Lab №6, task 7

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    //int step = 0;

    cout << "Enter the string in which the program will find the longest non palidrom substring :\n";
    cin >> s;

    int ans = -1;
    const int length = s.size();
    bool *palindrome_length = new bool[length + 1]();
    
    for (int i = 0; i < length; i++)
    {
        // for odd length
        for (int step = 1; i - step >= 0 && i + step < length; step++) {
            if (s[i - step] == s[i + step]) {
                palindrome_length[step * 2 + 1] = true;      
            }
            else {
                break;
            }
        }

        // for even length
        for (int step = 0; i - step >= 0 && i + step < length; step++) {
            if (s[i - step] == s[i + step + 1]) {
                palindrome_length[(step + 1) * 2] = true;
            }
            else {
                break;
            }
        }
    }

    for (int i = length; i > 1; i--) {
        if (!palindrome_length[i]) {
            ans = i;
            break;
        }
    }
    delete[] palindrome_length;

    cout << "\nThe length of the longest non palidrom: " << ans << '\n';

    return 0;
}
