#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, sum = 0;
	
	for (int i = 1; i <= 30; i++) {

		if (i % 2) {
			a = i;
			b = i * i;
		}
		else {
			a = i / 2;
			b = i * i * i;
		}
		sum += ((a - b) * (a - b));
	}
	
	cout << "Sum of (a[i] - b[i])^2, i = [1, 2, ..., 29, 30],\nwhere a[i] = (i % 2 ? i : i / 2), b[i] = (i % 2 ? i^2 : i^3)\nSum  =  " << sum << endl;
	return 0;
}