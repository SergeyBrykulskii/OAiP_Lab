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

int main() {
	int n, fi_sum = 0, se_sum = 0, th_sum = 0, fo_sum = 0;

	cout << "Enter the size of the array(n, n, n): ";
	n = tested_input_I();
	cout << "Enter the member of the matrix:\n";

	// Start. Dynamic mtrx declaration
	int*** array = new int** [n];

	for (int i = 0; i < n; i++) {
		array[i] = new int* [n];

		for (int j = 0; j < n; j++)
			array[i][j] = new int[n];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				array[i][j][k] = tested_input_I();

	for (int i = 0, j = 0, k = 0; i < n; i++, j++, k++)
		fi_sum += array[i][j][k];

	for (int i = n - 1, j = 0, k = 0; j < n; i--, j++, k++)
		se_sum += array[i][j][k];

	for (int i = 0, j = n - 1, k = 0; i < n; i++, j--, k++)
		th_sum += array[i][j][k];

	for (int i = n - 1, j = 0, k = 0; j < n; i--, j++, k++)
		fo_sum += array[i][j][k];

	//End.

	cout << "The largest sum of the elements of the diagonal: " << max(max(fi_sum, se_sum), max(th_sum, fo_sum));

	// Clearing of dinamic array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			delete[] array[i][j];
		delete[] array[i];
	}
	delete[] array;

	return 0;
}