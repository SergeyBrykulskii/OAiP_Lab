//  Lab №6, task 1, option 5
//  This program counts number of ones in groups with an odd number of characters
//  in a string consisting of groups of zeros and ones 

#include <iostream>

using namespace std;

int ContNumOfOnes(const char* str);

int main()
{
    int size, length_of_group = 0, num_of_ones = 0, num_of_odd_group = 1;
    char str[80] {};

    cout << "Enter string consisting of groups of zeros and ones: ";
    cin.getline(str, 80);

    cout << "Number of ones in groups with an odd number of characters: " << ContNumOfOnes(str) << '\n';
    return 0;
}

int ContNumOfOnes(const char* str) {
    int counter = 0, numOfOnes = 0, sizeOfGroup = 0, numOfOnesInGroup = 0;

    do {
        sizeOfGroup++;
        if (str[counter] == '1')
            numOfOnesInGroup++;
        if (str[counter] == ' ' || str[counter] == '\0') {
            if ((sizeOfGroup - 1) % 2) {
                numOfOnes += numOfOnesInGroup;
            }
            numOfOnesInGroup = 0;
            sizeOfGroup = 0;
        }
    } while (str[counter++] != '\0');

    return numOfOnes;
}