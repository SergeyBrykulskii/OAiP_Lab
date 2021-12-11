#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long sum = 0, n;
	double a;

	cout << "This program calculates sum, you must enter the number of members of the sum and than enter that members\n";
	cout << "Enter number of members: ";

	while (!(cin >> n)) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again\nEnter number of members: ";
	}

	cout << "Enter number:\n";

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ") ";
		while (!(cin >> a)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Incorrect input, try again\n" << i + 1 << ") ";
		}
		sum += (a * pow(-2, i));
	}

	cout << sum << endl;
	return 0;
}