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

	int bor, array[100][100], n, m, sum = 0, prod = 1;
	
	cout << "Enter the size of array(n, m): ";
	n = tested_input_I();
	m = tested_input_I();
	cout << "Enter the memmbers of array:\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			array[i][j] = tested_input_i();

	bor = min(n, m);

	for (int i = 0, j = 0; i < bor; i++, j++) {
		sum += array[i][j];
	}

	for (int i = n - 1, j = 0; j < bor; i--, j++) {
		prod *= array[i][j];
	}
	cout << "Sum of the elements of the main diagonal: " << sum << "\nProduct of the elements of the side diagonal: " << prod << endl;
	return 0;
}