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
	while (!(cin >> a) || (a != 1 && a != 0)) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int main() {
	int n;

	cout << "Enter the number of members of the array: ";
	n = tested_input_I();
	cout << "Fill the array with 0 or 1:\n";

	int **array = new int* [n];

	for (int i = 0; i < n; i++) {
		array[i] = new int[n];

		for (int j = 0; j < n; j++)
			array[i][j] = tested_input_i();
	}

	cout << "Array rotated 90 degrees clockwith:\n";

	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) 
			cout << array[i][j] << " ";

		cout << endl;
	}
	
	// Clearing of dinamic array
	for (int i = 0; i < n; i++) 
		delete[] array[i];
	delete[] array;

	return 0;
}