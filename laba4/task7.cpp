#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

// Natural number check
int tested_input_I() {
	int a;
	while (!(cin >> a) || a < 0) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cout << "Incorrect input, try again:\n";
	}

	return a;
}

int main(){ 
	stringstream ss;
	string s;
	int num, dubS;

	cout << "Enter number: ";
	dubS = tested_input_I();
	cout << "Enter number of the digit: ";
	num = tested_input_I();

	ss.clear();
	ss << dubS;
	ss >> s;

	cout << "Length of the number: " << s.size() << endl;
	cout << "Digit under the number " << num << ": " << s[s.size() - 1 - num];

	return 0;
} 