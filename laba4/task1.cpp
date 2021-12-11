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

	int array[1000], n;

	cout << "Enter the number of members of the array: ";
	n = tested_input_I();
	cout << "Enter the members of the array: ";

	for (int i = 0; i < n; i++)
		array[i] = tested_input_i() ;

	for (int i = 0; i < n - 1; i++) {
		int k = 0;

		for (int j = i + 1; j < n; j++) {
			if (array[i] == array[j]) {
				array[j] = 0;
				k++;
			}
		}
		if (k)
			array[i] = 0;
	}

	cout << "Non-repeating array members:\n";

	for (int i = 0, j = 1; i < n; i++)
		if (array[i])
		{
			cout << j << ") " << array[i] << endl;
			j++;
		}

	return 0;
}