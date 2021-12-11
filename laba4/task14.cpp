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

// Char('.', '*') check
char tested_input_c() {
	char a;
	while (!(cin >> a) || (a != '.' && a != '*')) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int main() {
	int n, m, num = 0;
	char a;
	bool s1, s2, s3, s4, s5, s6, s7, s8;

	cout << "Enter field size(n, m): ";
	n = tested_input_I();
	m = tested_input_I();
	cout << "Fill in the field with '.' and '*':\n";

	// Start. Declaration and filling of dynamic array 
	char** mtrx = new char* [n + 2];

	for (int i = 0; i < n + 2; i++)
		mtrx[i] = new char[m + 2];
	//End.

	for (int i = 1; i <= n ; i++) 
		for (int j = 1; j <= m; j++) 
			mtrx[i][j] = tested_input_c();

	for (int i = 0; i < n + 2; i++) {
		mtrx[i][0] = '.';
		mtrx[i][m + 1] = '.';
	}

	for (int i = 0; i < m + 2; i++) {
		mtrx[0][i] = '.';
		mtrx[n + 1][i] = '.';
	}

	cout << "\nIt's your fild:\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << mtrx[i][j] << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			num = 0;
			if (mtrx[i][j] == '.') {
				s1 = mtrx[i][j + 1] == '*';
				s2 = mtrx[i + 1][j] == '*';
				s3 = mtrx[i + 1][j + 1] == '*';
				s4 = mtrx[i - 1][j - 1] == '*';
				s5 = mtrx[i - 1][j] == '*';
				s6 = mtrx[i][j - 1] == '*';
				s7 = mtrx[i - 1][j + 1] == '*';
				s8 = mtrx[i + 1][j - 1] == '*';

				num += (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8);

				if (num)
					mtrx[i][j] = 48 + num;
			}

		}

	}

	cout << "\nNew field:\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << mtrx[i][j] << " ";
		cout << endl;
	}

	// Clearing of dinamic array
	for (int i = 0; i < n; i++)
		delete[] mtrx[i];
	delete[] mtrx;

	return 0;
}