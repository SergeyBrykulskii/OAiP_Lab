#include <iostream>
#include <vector>
#include "my_library.h"

using namespace std;

vector<int> GetVector(const int vSize) {
	vector<int> v(vSize);

	cout << "Enter members of vector:\n";

	for (int i = 0; i < vSize; i++)
		cin >> v[i];

	return v;
}


int FindMaximum(const vector<int>& a, const vector<int>& b, const int asize, const int bsize)
{
	int maximum = a[0] * b[0];

	for (int i = 0; i < asize; i++)
		for (int j = 0; j < bsize; j++)
			if (a[i] * b[j] > maximum)
				maximum = a[i] * b[j];

	return maximum;
}