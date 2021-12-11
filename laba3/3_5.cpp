#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int numberOfMembers, numberOfX;
	bool correct1 = 0, correct2 = 0;

	string dubNumberOfMembers, dubNumberOfX;
	stringstream ss;

	cout << "This program expands the function in a row and calculates the value using the formula\n";
	while (!correct1) {
		correct1 = 1;

		cout << "Enter the number of members of the series: ";
		getline(cin, dubNumberOfMembers);

		for (int i = 0; i < dubNumberOfMembers.size(); i++) {
			if (!isdigit(dubNumberOfMembers[i])) {
				cout << "Incorrect input, try again\n";
				correct1 = 0;
				break;
			}
		}
	}
	
	ss.clear();
	ss.str(dubNumberOfMembers);
	ss >> numberOfMembers;

	while (!correct1) {
		correct1 = 1;

		cout << "Enter the number of series: ";
		getline(cin, dubNumberOfX);

		for (int i = 0; i < dubNumberOfX.size(); i++) {
			if (!isdigit(dubNumberOfX[i])) {
				cout << "Incorrect input, try again\n";
				correct2 = 0;
				break;
			}
		}
	}

	ss.clear();
	ss.str(dubNumberOfX);
	ss >> numberOfX;

	for (int i = 0; i < numberOfX; i++) {
		double k = 0, x, sumOfSeries = 0, memberOfSeries = 1, shortSum;
		bool correct3;
		string dubX;

		while (!correct3) {
			correct3 = 1;

			cout << "Enter x(0.1 <= x <= 1): ";
			getline(cin, dubX);

			for (int j = 0; j < dubX.size(); j++) {
				if (dubX[j] == '.') {
					k++;
					if (j == 0) {
						correct3 = 0;
						cout << "Incorrect input, try again\n";
						break;
					}
				}
				if (k == 2) {
					correct3 = 0;
					cout << "Incorrect input, try again\n";
					break;
				}
				if (!isdigit(dubX[j]) && dubX[j] != '.') {
					cout << "Incorrect input, try again\n";
					correct3 = 0;
					break;
				}
				ss.clear();
				ss.str(dubX);
				ss >> x;

				if (x < 0.1 || x > 1) {
					correct3 = 0;
					cout << "Incorrect input, try again\n";
				}
			}
		}

		int j = 0;
		while(j <= numberOfMembers) {
			sumOfSeries += memberOfSeries;
			j++;
			memberOfSeries = memberOfSeries / j / (2 * (j - 1) + 1) * x * x * (2 * j + 1);
		}

		shortSum = (1 + 2 * x * x) * exp(x * x);

		cout << "Sum by series: " << sumOfSeries << endl;
		cout << "Sum by formula: " << shortSum << endl << endl;
	}

	return 0;
}