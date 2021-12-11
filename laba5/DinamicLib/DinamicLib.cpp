#include "pch.h"
#include "DinamicLib.h"
#include <vector>
#include <limits>

using namespace std;

#if defined(max)
#undef max
#endif

int FindMinimun(const vector<int>& v, const int& position_of_num, const int& size) {

	if (size == 1) {
		return v[position_of_num];
	}
	if (size % 2) {

		return min(min(FindMinimun(v, position_of_num, size / 2), FindMinimun(v, position_of_num + (size / 2), size / 2)), v[position_of_num + size - 1]);
	}
	else {
		return min(FindMinimun(v, position_of_num, size / 2), FindMinimun(v, (position_of_num + (size / 2)), size / 2));
	}
}

int GetIntegerNumber() {
	int a;
	while (!(std::cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int GetNaturalNumber() {
	int a;
	while (!(cin >> a) || a < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

double GetRealNumber() {
	double a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}