#pragma once
#include <vector>

using namespace std;

int GetNaturalNumber();

double GetRealNumber();

int GetIntegerNumber();


vector<vector<int>> GetMatrixOfInt(const int &width, const int &length);

vector<int> FindEvenFromDiagonal(const vector<vector<int>> &matrix, const int &width, const int &length);

int CountProductOfArray(const vector<int> &array);

void PrintMatrixOfInt(const vector<vector<int>> &matrix);


vector<vector<double>> GetMatrixOfReal(const int &width, const int &length);

void FindZeroInMatrix(const vector<vector<double>> &matrix, const int &width, const int &length, int& sum);

void PrintMatrixOfReal(const vector<vector<double>> &matrix);

void ReverseMatrix(vector<vector<double>> &matrix, const int &width);


vector<int> MakeArray(const vector<vector<int>> &matrix, const int &width, const int &length);

void PrintArrayOFInt(const vector<int> &array);

double CountAverageOfArray(const vector<int> &array);


int RecursionForFirstTask(const int &num);