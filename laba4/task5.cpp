#include <iostream>
#include <iomanip>

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

//  Check for real numbers
int tested_input_D() {
	double a;
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
	cout << "Enter the member of the mtrx:\n";

	// Start. Dynamic mtrx declaration
	double** mtrx = new double* [n];

	for (int i = 0; i < n ; i++) {
		mtrx[i] = new double[m];
		for (int j = 0; j < m; j++)
			mtrx[i][j] = tested_input_D();
	}
	//End.

	mtrx[0][0] = (mtrx[0][1] + mtrx[1][0] + mtrx[1][1]) / 3;
	mtrx[n - 1][0] = (mtrx[n - 1][1] + mtrx[n - 2][0] + mtrx[n - 2][1]) / 3;
	mtrx[0][m - 1] = (mtrx[0][m - 2] + mtrx[1][m - 2] + mtrx[1][m - 1]) / 3;
	mtrx[n - 1][m - 1] = (mtrx[n - 1][m - 2] + mtrx[n - 2][m - 2] + mtrx[n - 2][m - 1]) / 3;
	
	for (int i = 1; i < n - 1; i++) {
		mtrx[i][0] = (mtrx[i - 1][0] + mtrx[i - 1][1] + mtrx[i][1] + mtrx[i + 1][1] + mtrx[i + 1][0]) / 5;
		mtrx[i][m - 1] = (mtrx[i - 1][m - 1] + mtrx[i - 1][m - 2] + mtrx[i][m - 2] + mtrx[i + 1][m - 2] + mtrx[i + 1][m - 1]) / 5;
	}

	for (int i = 1; i < m - 1; i++) {
		mtrx[0][i] = (mtrx[0][i - 1] + mtrx[1][i - 1] + mtrx[1][i] + mtrx[1][i + 1] + mtrx[0][i + 1]) / 5;
		mtrx[n - 1][i] = (mtrx[n - 1][i - 1] + mtrx[n - 2][i - 1] + mtrx[n - 2][i] + mtrx[n - 2][i + 1] + mtrx[n - 1][i + 1]) / 5;
	}

	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			mtrx[i][j] = (mtrx[i-1][j-1] + mtrx[i-1][j] + mtrx[i-1][j+1] + mtrx[i][j-1] + mtrx[i][j +1] + mtrx[i+1][j-1] + mtrx[i+1][j] + mtrx[i+1][j+1]) / 8;

	cout << "The result of smoothing this matrix\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(8) << mtrx[i][j] << " ";
		cout << endl;
	}
	
	// Clearing of dinamic array
	for (int i = 0; i < n; i++)
		delete[] mtrx[i];
	delete[] mtrx;

	cout << "Number of the local minima of the matrix: " << numOfMem;

	return 0;
} 