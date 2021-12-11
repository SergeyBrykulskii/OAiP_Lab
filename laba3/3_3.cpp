#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const double pi = 3.14159265;

	cout << "This program calculates the values of the functionon(Y = sin(x) - cos(x)) \nOn the interval [0, pi / 2] with a step (pi / 40)\n";

	for (double i = 0; i < pi / 2; i += (pi / 40)) {
		cout << "sin(x) - cos(s)   =   " << sin(i) - cos(i) << endl;
	}
	
	return 0;
}