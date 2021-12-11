#include <iostream>

using namespace std; 

int main()
{
	int n = 1;
	double d, sum = 0;
	
	do {
		d = pow(1. / 2, n) + pow(1. / 3, n);
		sum += d;
		n++;
	} while (d > 0.001);

	cout << "Sum of d[n], where d[n] = (1/2)^n + (1/3)^n, while d[n] > 0.001\nSum  =  " << sum << endl;

	return 0;
}