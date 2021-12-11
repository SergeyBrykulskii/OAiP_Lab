#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num = 1;

	cout << "Armstrong's numbers(from 153 to 1000000): " << endl;

	for (int i = 153; i < 1e6; i++) {
		int n = 0, sum = 0, j = i;
		while (j) {
			n++;
			j /= 10;
		}
		j = i;
		while (j) {
			sum += pow(j % 10, n);
			j /= 10;
		}
		if (sum == i) {
			cout << num++ << ") " << i << endl;
		}
	}
	
	return 0;
}