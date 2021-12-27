//  Lab №6, task 2
//  This program insert specified character after each word of the text ending with given substring  

//  Lab №6, task 2, option 5

#include <iostream>

using namespace std;

bool CheckStopword(const char* word, const int& lengthOfWord);

bool FindSubstringInEndOFWord(const char* word, const int& lengthOfWord, const char* substring, const int& lengthOfSubstring);

int main()
{   
    char *substring = 0, *word = 0, character;
    int lengthOfSubstr, sizeOfStr = 2;
    
    substring = (char*)malloc(sizeOfStr * sizeof(char)); // memory allocation for the first two elements
    
    cout << "Enter substring: ";

    // Данное выделение памяти под массив char схоже с выделением памяти в vector 
    // Является копромиссом между оптимизацией памяти и скорости работы программы
    // Как только нужена дополнительная память под новые элементы размер массива увиличивается в два раза

    for (lengthOfSubstr = 0; (substring[lengthOfSubstr] = getchar()) != '\n'; lengthOfSubstr++) { // input character one by one befor line feed
        if (lengthOfSubstr == sizeOfStr - 1) { // allocation of new memory if charecters become the same as allocated memory
            substring = (char*)realloc(substring, (sizeOfStr *= 2) * sizeof(char));
        }
    }
    
    substring = (char*)realloc(substring, (lengthOfSubstr + 1) * sizeof(char)); // appends null terminator to the nd of the string 
    substring[lengthOfSubstr] = '\0';

    cout << "Enter character: ";
    cin >> character;
    
    cout << "Enter text. In the end of the text enter \"stop\":   ";
    
    while (true) {  //  Endless cycle(you can enter large number of words befor word "stop")
        int lengthOfWord;
        sizeOfStr = 2;

        word = (char*)malloc(sizeOfStr * sizeof(char));

        for (lengthOfWord = 0; (word[lengthOfWord] = getchar()) != ' ' && word[lengthOfWord] != '\n'; lengthOfWord++) {
            if (lengthOfWord == sizeOfStr - 1) {
                word = (char*)realloc(word, (sizeOfStr *= 2) * sizeof(char));
            }
        }

        word = (char*)realloc(word, (lengthOfWord + 1) * sizeof(char));
        word[lengthOfWord] = '\0';

        if (CheckStopword(word, lengthOfWord)) {
            break;
        }

        //  Every word of the text
        cout << word << " ";

        //  if word ends with a substring, the character is output
        if (FindSubstringInEndOFWord(word, lengthOfWord, substring, lengthOfSubstr))
            cout << character << " ";

        free(word);
    }
    return 0;
}


bool FindSubstringInEndOFWord(const char* word, const int& lengthOfWord, const char* substring, const int& lengthOfSubstring) {
    if (lengthOfSubstring > lengthOfWord) {
        return 0;
    }

    for (int i = lengthOfWord - 1, j = lengthOfSubstring - 1; j >= 0; i--, j--)
    {
        if (word[i] != substring[j])
            return 0;
    }

    return 1;
}

bool CheckStopword(const char *word, const int &lengthOfWord) {
    if (lengthOfWord == 4) {
        char stop[5] = { 's', 't', 'o', 'p' };

        for (int i = 0; i < lengthOfWord; i++) {
            if (word[i] != stop[i])
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}