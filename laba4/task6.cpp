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
	int n, m;

	cout << "Enter the size of the matrix(n, m): ";
	n = tested_input_I();
	m = tested_input_I();
	cout << "Enter the member of the matrix:\n";

	// Start. Dynamic mtrx declaration
	int** mtrx = new int* [n + 1];

	for (int i = 0; i <= n; i++) {
		mtrx[i] = new int[m + 1];
	}
	//End.

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mtrx[i][j] = tested_input_i();

	for (int i = 0; i <= n; i++) 
		mtrx[i][0] = INT_MIN;

	for (int i = 0; i <= m; i++)
		mtrx[0][i] = INT_MIN;

	cout << "New matrix:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mtrx[i][j] = max(max(mtrx[i - 1][j], mtrx[i][j - 1]), mtrx[i - 1][j - 1]);
			cout << setw(8) << mtrx[i][j] << " ";
		}
		cout << endl;
	}

	// Clearing of dinamic array
	for (int i = 0; i <= n; i++)
		delete[] mtrx[i];
	delete[] mtrx;

	return 0;
}