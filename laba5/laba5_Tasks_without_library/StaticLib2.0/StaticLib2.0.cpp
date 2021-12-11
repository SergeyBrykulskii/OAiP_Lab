#include "StaticLib2.0.h"
#include <iostream>
#include <vector>

// Common functions
int GetNaturalNumber() {
	unsigned long long a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

double GetRealNumber() {
	double a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int GetIntegerNumber() {
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}
 
// Funtions for first task
vector<vector<int>> GetMatrixOfInt(const int &width, const int &length) {
	vector<vector<int>> matrix(width, vector<int>(length));

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			cout << "Enter(integer) element of matrix a[" << i + 1 << "][" << j + 1 << "]: ";
			matrix[i][j] = GetIntegerNumber();
		}
	}
	cout << "Your matrix:\n";

	PrintMatrixOfInt(matrix);
	cout << '\n';

	return matrix;
}

vector<int> FindEvenFromDiagonal(const vector<vector<int>> &matrix, const int &width, const int &length) {
	vector<int> array;

	for (int i = 0, j = 0; i < width && j < length; i++, j++) {
		if (!(matrix[i][j] % 2)) {
			array.push_back(matrix[i][j]);
		}
	}

	return array;
}

int CountProductOfArray(const vector<int> &array){
	const int size = array.size();
	if (!size) {
		cout << "\nThere aren't even elements on diagonal\n";
	}
	else {
		int product = 1;

		for (int i = 0; i < size; i++)
			product *= array[i];
		return product;
	}
}

void PrintMatrixOfInt(const vector<vector<int>> &matrix) {
	for (auto i : matrix) {
		for (auto j : i)
			cout << j << " ";
		cout << '\n';
	}
}

// Funtions for second task

vector<vector<double>> GetMatrixOfReal(const int &width, const int &length) {
	vector<vector<double>> matrix(width, vector<double>(length));

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			cout << "Enter(real) element of matrix a[" << i + 1 << "][" << j + 1 << "]: ";
			matrix[i][j] = GetRealNumber();
		}
	}
	cout << "Your matrix:\n";

	PrintMatrixOfReal(matrix);

	return matrix;
}

void FindZeroInMatrix(const vector<vector<double>> &matrix, const int &width, const int &length, int &sum) {
	cout << "Indices of zero elements:\n";

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			if (!matrix[i][j]) {
				cout << "[" << i + 1 << "]" << "[" << j + 1 << "]\n";
				sum++;
			}
		}
	}
}
void ReverseMatrix(vector<vector<double>> &matrix, const int &width) {
	reverse(matrix.begin(), matrix.end());

	for (int i = 0; i < width; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

void PrintMatrixOfReal(const vector<vector<double>> &matrix) {
	for (auto i : matrix) {
		for (auto j : i)
			cout << j << " ";
		cout << '\n';
	}
}

// Functions for third task

vector<int> MakeArray(const vector<vector<int>> &matrix, const int &width, const int &length) {
	vector<int> array;

	for (int i = 0; i < width; i++) {
		for (int j = 1; j < length; j+=2) {
			if (matrix[i][j] % 2)
				array.push_back(matrix[i][j]);
		}
	}

	return array;
}

void PrintArrayOFInt(const vector<int> &array) {
	for (auto element : array) {
		cout << element << " ";
	}
	cout << '\n';
}

double CountAverageOfArray(const vector<int> &array) {
	const int size = array.size();
	double average = 0;

	for (auto element : array) {
		average += double(element) / size;
	}

	return average;
}

// Functions for first additional task

int RecursionForFirstTask(const int &num) {
	if (num == 0)
		return 0;

	if (num % 10)
		return (num % 10);

	return RecursionForFirstTask(num / 10);	
}