#include <iostream >
#include <vector>
#include "DinamicLib.h"

using namespace std;

int main()
{
	int size;

	cout << "Enter the size of array: ";
	cin >> size;

	vector<int> array(size);

	cout << "Enter members of the array: ";

	for (int i = 0; i < size; i++)
		array[i] = GetIntegerNumber();

	cout << FindMinimun(array, 0, size);

	return 0;
}
