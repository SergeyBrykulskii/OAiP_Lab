//  Lab №6, task 4
/*  1 апреля 20 ? ? года будет проведена реформа английского языка,
    позволяющая облегчить его освоение иностранцами и английскими
    школьниками.Во - первых, из алфавита уберут четыре буквы C, Q, W и X(на
    клавиатуре компьютера вместо них будут клавиши, вызывающие программы
    Word, eXcel и другие).Вместо c перед буквами e, i, y нужно будет писать
    букву s, а в остальных случаях – букву k.Вместо буквы q нужно будет писать
    букву k, вместо сочетания qu –
    kv, вместо x – ks, а вместо w – v.Во - вторых, сочетание букв ph будет
    записываться как f, you и oo – как u, ee – как i, th – как z.Кроме того, все
    двойные согласные(включая образовавшиеся после замен), вызывающие
    большие трудности у учащихся, станут одинарными, например, apple после
    реформы нужно писать как aple.
    В связи с реформой нужно переработать огромное количество текстов.
    Напишите программу, выполняющую эту работу.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ChangeC(string &s) {
    const int size = s.size();
    for (int i = 0; i < size - 1; i++) {
        if (tolower(s[i]) == 'c' && (tolower(s[i + 1]) == 'c' || tolower(s[i + 1]) == 'i' || tolower(s[i + 1]) == 'y')) {
            s[i] += 's' - 'c';
        }
        else if (tolower(s[i]) == 'c') {
            s[i] += 'k' - 'c';
        }
    }

    if (s[size] == 'c') {
        s[size] += 'k' - 'c';
    }
}

void ChangeQ(string &s) {
    const int size = s.size();

    for (int i = 0; i < size; i++) {
        if (tolower(s[i]) == 'q' && tolower(s[i + 1]) == 'u') {
            s[i] += 'k' - 'q';
            s[i + 1] += 'v' - 'u';
        }
        else if (tolower(s[i]) == 'q') {
            s[i] += 'k' - 'q';
        }

        if (s[size] == 'q') {
            s[i] += 'k' - 'q';
        }
    }
}

void ChangeX(string &s) {
    const int size = s.size();

    for (int i = 0; i < size; i++) {
        if (tolower(s[i]) == 'x') {
            s[i] += 'k' - 'x';
            s.insert(s.begin() + i + 1, 's');
        }
    }
}

void ChangeW(string &s) {
    const int size = s.size();

    for (int i = 0; i < size; i++) {
        if (tolower(s[i]) == 'w') {
            s[i] += 'v' - 'w';
        }
    }
}

void ChangePH(string &s) {
    const int size = s.size();

    for (int i = 0; i < size - 1; i++) {
        if (tolower(s[i]) == 'p' && tolower(s[i]) == 'h') {
            s[i] += 'f' - 'p';
            s.erase(s.begin() + i + 1);
        }
    }
}

void ChangeYOU(string &s) {
    const int size = s.size();

    for (int i = 0; i < size - 2; i++) {
        if (tolower(s[i]) == 'y' && tolower(s[i + 1]) == 'o' && tolower(s[i + 2]) == 'u') {
            s[i] += 'u' - 'y';
            s.erase(s.begin() + i + 1, s.begin() + i + 3);
        }
    }
}

void ChangeOO(string &s) {
    const int size = s.size();

    for (int i = 0; i < size - 1; i++) {
        if (tolower(s[i]) == 'o' && tolower(s[i + 1]) == 'o') {
            s[i] += 'u' - 'o';
            s.erase(s.begin() + i + 1);
        }
    }
}

void ChangeEE(string &s) {
    const int size = s.size();

    for (int i = 0; i < size - 1; i++) {
        if (tolower(s[i]) == 'e' && tolower(s[i + 1]) == 'e') {
            s[i] += 'i' - 'e';
            s.erase(s.begin() + i + 1);
        }
    }
}

void ChangeTH(string& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (tolower(s[i]) == 't' && tolower(s[i + 1]) == 'h') {
            s[i] += 'z' - 't';
            s.erase(s.begin() + i + 1);
        }
    }
}

void ChangeDoubleconsonants(string &s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (tolower(s[i]) == tolower(s[i + 1])) {
            s.erase(s.begin() + i + 1);
        }
    }

}
int main()
{
    string text;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    //  Так как текст может быть давольно длинным я реализовал ввод из файла
    //  соответствующие файлы подключены к проекту
    //  !inputFile.eof() считывает пока файл не пуст
    //  далее каждая конкретная функция реализует конкретную правку

    while (!inputFile.eof()) {
        cin.ignore(32767, '\n');
        getline(inputFile, text);
        ChangeC(text);
        ChangeQ(text);
        ChangeX(text);
        ChangeW(text);
        ChangePH(text);
        ChangeYOU(text);
        ChangeOO(text);
        ChangeTH(text);
        ChangeEE(text);
        ChangeDoubleconsonants(text);

        outputFile << text << endl;
    }

    return 0;
}