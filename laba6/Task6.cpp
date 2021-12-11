//  Lab №6, task 6
//  This program calculates the number of different anagrams of the entered word

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int array[26]{}, ans = 1, num = 1;

    cout << "Enter word to calculate how many different anagrams can be made from it:\n";
    cin >> s;
    
    for (int i = 0; i < s.size(); i++)
    {
        array[tolower(s[i]) - 97]++;
    }

    //  Кол-во различных анаграмм вычисляется по формуле:
    //  (кол-во букв в слове)! / ((кол-во повторений буквы1)! * ... * (кол-во повторений буквыN)!)
    //  Чтобы избежать переполнения в переменной ans делаем это постепенно в цикле
    
    for (int i = 0; i < 26; i++)
    {
        if (array[i] > 0) {
            for (int j = 1; j <= array[i]; j++) {
                ans *= num++;
                ans /= j;
            }
        }
    }

    cout << "\nNuber of anagrams of the entered word: " << ans << '\n';

    return 0;
}