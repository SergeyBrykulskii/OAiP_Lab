#include <iostream>
#include <iomanip>

using namespace std;

// Natural number check
int tested_input_I() {
	int a;

	while (!(cin >> a) || a < 0 || !(a % 2)) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int main() {
	int n, sum = 0, j = 0, a = 1;

	cout << "Enter the size of square(odd number): ";
	n = tested_input_I();

	int **array = new int *[n * 2 - 1];
	for (int i = 0; i < n * 2 - 1; i++) 
		array[i] = new int[n * 2 - 1];
	
	for (int i = 0; i < n * 2 - 1; i++)
		for (int j = 0; j < n * 2 - 1; j++)
			array[i][j] = 0;

	for (int k = 0; k < n; k++) {
		for (int i = n - 1 + k, j = 0 + k; i >= 0 + k; i--, j++) {
			array[i][j] = a++;
		}
	}
	
	for (int i = 0; i < n / 2; i++) 
		for (int j = n - 1 - i * 2; j < n + i * 2; j++) 
			if (array[i][j])
				array[i + n][j] = array[i][j];
	
	for (int j = 0; j < n / 2; j++) 
		for (int i = n - 1 - j * 2; i < n + j * 2; i++) 
			if (array[i][j])
				array[i][j + n] = array[i][j];
		
	for (int i = n * 2 - 2, k = 0; i > n * 2 - 2 - (n / 2); i--, k++) 
		for (int j = n - 1 - k * 2; j < n + k * 2; j++) 
			if (array[i][j])
				array[i - n][j] = array[i][j];

	for (int j = n * 2 - 2, k = 0; j > n * 2 - 2 - (n / 2); j--, k++) 
		for (int i = n - 1 - k * 2; i < n + k * 2; i++) 
			if (array[i][j])
				array[i][j - n] = array[i][j];


	cout << "\nMagic square:\n";

	for (int i = n / 2; i < n * 2 - 1 - n / 2; i++) {
		for (int j = n / 2; j < n * 2 - 1 - n / 2; j++)
			cout << setw(4) << array[i][j] << " ";
		cout << "\n";
	}

	// Clearing of dinamic array
	for (int i = 0; i < n * 2 - 1; i++)
		delete[] array[i];
	delete[] array;

	return 0;
}