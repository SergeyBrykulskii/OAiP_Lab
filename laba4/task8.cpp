#include <iostream> 
#include <string>
#include <cmath>

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

	int n, mn, mx, num_mn = 0, num_mx = 0;

	cout << "Enter the size of array: ";

	n = tested_input_I();

	int* array = new int[n];

	cout << "Enter members of the array: ";

	for (int i = 0; i < n; i++)
		array[i] = tested_input_i();

	mn = array[0];
	mx = array[0];

	for (int i = 1; i < n; i++) {
		if (array[i] < mn) {
			mn = array[i];
			num_mn = i;
		}
		if (array[i] > mx) {
			mx = array[i];
			num_mx = i;
		}
	}
	
	int start, finish;

	if (num_mx <= num_mn) {
		start = num_mx + 1;
		finish = num_mn;
	}
	else {
		start = num_mn + 1;
		finish = num_mx;
	}

	cout << "Final array: ";
	if (abs(num_mx - num_mn) > n / 2) {
		int finish2 = finish;

		for (int i = start; i < 2 * finish - n - 1; i++) {
			array[i] = array[finish2++];
		}
		// You must delete lishnie elements 
		for (int i = 0; i < 2 * finish - n - 1; i++) {
			cout << array[i] << " ";
		}
	}
	else {
		for (int i = start; i < finish; i++)
			array[i] = 0;
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}
	}
	cout << endl;

	// Clearing of dinamic array
	delete[] array;

	return 0;
}