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
	int n, dubN, sum = 0, j = 0;

	cout << "Enter the length of array: ";
	n = tested_input_I();

	dubN = n;
	int* array = new int[n]; 

	cout << "Enter the members of array: ";

	for (int i = 0; i < n; i++)
		array[i] = tested_input_i();
	
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) 
			if (array[i] == array[j]) {
				array[i] = INT_MIN;
				sum++;
			}

	dubN = n - sum;

	int *array_ans = new int[dubN];
	
	for (int i = 0; i < n; i++) {
		if (array[i] != INT_MIN) {
			array_ans[j] = array[i];
			j++;
		}
	}

	cout << "\nLength of new array: " << dubN << "\nNew array:   ";
	for (int i = 0; i < dubN; i++)
		cout << array_ans[i] << " ";

	// Clearing of dinamic array
	delete[] array;
	delete[] array_ans;

	return 0;
}