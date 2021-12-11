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

	cout << "Enter the size of the matrix(n, n): ";
	n = tested_input_I();

	// Start. Dynamic mtrx declaration
	int **mtrx1 = new int* [n], **mtrx2 = new int* [n], **mtrx_ans = new int* [n];
	for (int i = 0; i < n; i++) {
		mtrx1[i] = new int[n];
		mtrx2[i] = new int[n];
		mtrx_ans[i] = new int[n];
	}
	//End.

	cout << "Enter the member of the first matrix:\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mtrx1[i][j] = tested_input_i();

	cout << "Enter the member of the second matrix:\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mtrx2[i][j] = tested_input_i();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			mtrx_ans[i][j] = 0;

			for (int k = 0; k < n; k++) {
				mtrx_ans[i][j] += (mtrx1[i][k] * mtrx2[k][j]);
				cout << mtrx1[i][k] << "*" << mtrx1[k][j] << "+";
			}
			cout << endl;
		}
			

	cout << "Matrix product:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(8) << mtrx_ans[i][j] << " ";
		}
		cout << endl;
	}

	// Clearing of dinamic array
	for (int i = 0; i < n; i++) {
		delete[] mtrx1[i];
		delete[] mtrx2[i];
		delete[] mtrx_ans[i];
	}
	delete[] mtrx1;
	delete[] mtrx2;
	delete[] mtrx_ans;

	return 0;
}