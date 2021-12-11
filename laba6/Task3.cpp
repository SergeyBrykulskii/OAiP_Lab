//  Lab №6, task 3, option 5
//  This program looks for the average value of the length of a string in an array of strings. Strings,
//  the length of which is more than average - cuts, less - adds gaps

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string *arrayOfString = NULL;
    int size, averageLength = 0;

    cout << "Enter size of array of string: ";
    cin >> size;

    arrayOfString = new string[size];

    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " string from array: ";
        cin.ignore(32767, '\n');
        getline(cin, arrayOfString[i]);

        averageLength += arrayOfString[i].size();
    }

    averageLength /= size;

    for (int i = 0; i < size; i++)
    {
        if (arrayOfString[i].size() > averageLength) {
            arrayOfString[i].erase(averageLength);
        }
        else if (arrayOfString[i].size() < averageLength) {
            for (int j = 0; j < averageLength - arrayOfString[i].size(); j++)
            {
                arrayOfString[i] += "_";
            }
        }
    }

    cout << "Сorrected strings:\n";

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") " << arrayOfString[i] << '\n';
    }

    return 0;
}