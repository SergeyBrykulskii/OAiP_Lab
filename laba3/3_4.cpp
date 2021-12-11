#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n, sum = 0;
	bool correct = 0;
	string dubN;
	stringstream ss;

	cout << "This program calculates the sum of even numbers from 1 to n";

	while (!correct) {
		correct = 1;

		cout << "Enter number(n > 1): ";
		getline(cin, dubN);

		for (int i = 0; i < dubN.size(); i++) {
			if (!isdigit(dubN[i])) {
				correct = 0;
				cout << "Incorrect input, try again\n";
				break;
			}
		}

		ss.clear();
		ss.str(dubN);
		ss >> n;

		if (n <= 1) {
			correct = 0;
			cout << "Incorrect input, try again\n";
		}
	}


	if (n > 1) {
		for (int i = 2; i <= n; i += 2) {
			sum += i;
		}

		cout << "Sum of even numbers from 1 to " << n << "\nFirst way: ";
		cout << sum;

		n /= 2;
		cout << "\nSecond way: " << n * (n + 1) << endl;
	}
	else {
		cout << "Your number isn't correct, try again." << endl;
		main();
	}
	return 0;
}