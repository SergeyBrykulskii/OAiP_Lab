#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double areaParts, mn = 3, root = 0;

	cout << "This program calculates the approximate root of the equation\n";
	cout << "How many parts you want to split the root search area into?\nEnter number: ";
	cin >> areaParts;

	areaParts = 2 / areaParts;

	for (double i = -1; i <= 1; i += areaParts) {
		if (fabs(coshl(i * i) - acos(i)) < mn) {
			mn = fabs(coshl(i * i) - acos(i));
			root = i;
		}
	}
	cout << "The root of the equation: " << root << endl;
	return 0;
}