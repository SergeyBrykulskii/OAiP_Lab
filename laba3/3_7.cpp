#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "This program calculates a two-digit number that has the property that a cube the sum of its digits"
	 " is equal to the square of the number itself\n";

	for (int i = 10; i < 100; i++) {
		if (i * i == pow(i / 10 + i % 10, 3)) {
			cout << i << endl;
		}
	}

	return 0;
}