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

int main() {
	int n, sum = 1, a;

	cout << "Enter the number of extension: ";
	n = tested_input_I();
	
	for (int i = 0; i < n; i++) {
		a = tested_input_I();
		sum += a;
	}
	
	sum -= n;

	cout << "The number of sockets that Misha will receive:  " << sum;
	return 0;
}