#include <iostream>

using namespace std;

// Natural number check
int tested_input_I() {
	int a;
	while (!(cin >> a) || a < 0) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

// Check for integers
int tested_input_i() {
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int main() {
	int n, m, numOfMem = 0;
	bool s1, s2, s3, s4, s5, s6, s7, s8;

	cout << "Enter the size of the mtrx(n, m): ";

	n = tested_input_I();
	m = tested_input_I();

	// Start. Dynamic mtrx declaration
	int** mtrx = new int* [n+2];

	for (int i = 0; i < n + 2; i++) {
		mtrx[i] = new int[m + 2];
	}
	//End.

	cout << "Enter the member of the mtrx:\n";

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mtrx[i][j] = tested_input_i();

	for (int i = 0; i < n + 2; i++) {
		mtrx[i][0] = INT_MAX;
		mtrx[i][m + 1] = INT_MAX;
	}

	for (int i = 0; i < m + 2; i++) {
		mtrx[0][i] = INT_MAX;
		mtrx[n + 1][i] = INT_MAX;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			// I moved the check into separate variables of type bool for better readability
			s1 = mtrx[i][j] < mtrx[i + 1][j + 1];
			s2 = mtrx[i][j] < mtrx[i - 1][j - 1];
			s3 = mtrx[i][j] < mtrx[i + 1][j];
			s4 = mtrx[i][j] < mtrx[i - 1][j];
			s5 = mtrx[i][j] < mtrx[i][j + 1];
			s6 = mtrx[i][j] < mtrx[i][j - 1];
			s7 = mtrx[i][j] < mtrx[i + 1][j - 1];
			s8 = mtrx[i][j] < mtrx[i - 1][j + 1];

			if (s1 && s2 && s3 && s4 && s5 && s6 && s7 && s8) numOfMem++;
		}

	cout << "Number of the local minima of the matrix: " << numOfMem;

	// Clearing of dinamic array
	for (int i = 0; i < n + 2; i++)
		delete[] mtrx[i];
	delete[] mtrx;

	return 0;
}