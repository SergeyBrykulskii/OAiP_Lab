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
	int n, sum = 0, j = 0, a = 1;

	cout << "Enter the size of square: ";
	n = tested_input_I();

	int **array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			array[i][k] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		array[i][0] = (i + 1) * (i + 1);
		array[0][i] = i * i + 1;

		for (int j = 1; j < i; j++) {
			array[i][j] = array[i][j - 1] - 1;

		}
		
		for (int j = 1; j <= i; j++) {
			array[j][i] = array[j - 1][i] + 1;

		}
	}

	cout << "Square that we need:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << setw(4) << array[i][j] << " ";
		cout << "\n";
	}

	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	return 0;
}