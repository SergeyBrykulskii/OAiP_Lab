//  Lab №6, task 5
//	Первая строка содержит одно целое число t(1 ≤ t ≤ 100) — количество
//	наборов входных данных, которые необходимо обработать.
//	Описание каждого из наборов входных данных содержит три строки.Первая
//	из них содержит два целых числа : L и m(1 ≤ L ≤ 109)
//		, 1 ≤ m ≤ 104
//	.Вторая и
//	третья строки содержат соответственно строки S1 и S2.Они непусты, состоят
//	из строчных букв латинского алфавита, их длины не превышают 200
//	символов.

#include <iostream>
#include <string>

using namespace std;

int MyPow(const int x, const int n, const int m);

int main()
{
	int t, result_length, module_;
	string s1, s2;

	cout << "Enter number of input datasets: ";
	cin >> t;
	
	while (t--)
	{
		cout << "Enter the length of the required strings: ";
		cin >> result_length;

		cout << "Enter module of division: ";
		cin >> module_;

		cout << "Enter suffix and prefix:\n";
		cin >> s1 >> s2;

		int length1 = s1.size(), length2 = s2.size();
		if (length1 > result_length || length2 > result_length) {
			cout << "Number of possible strings: " << 0 << '\n';
		}
		else if (length1 + length2 >= result_length) {
			int ans = 2;

			for (int i = result_length - length2, j = 0; i < length1; i++, j++) {
				if (s1[i] != s2[j]) {
					ans--;
					break;
				}
			}

			for (int i = result_length - length1, j = 0; i < length2; i++, j++) {
				if (s1[j] != s2[i]) {
					ans--;
					break;
				}
			}
			
			cout << "Number of possible strings: " << ans % module_ << '\n';
		}
		else {
			cout << "Number of possible strings: " << MyPow(26, result_length - length1 - length2, module_) * 2 % module_ << '\n';
		}
	}

	return 0;
}

int MyPow(const int x, const int n, const int m) {
	if (n == 0) {
		return 1;
	}

	int z = MyPow(x, n / 2, m);

	if (n % 2 == 0) {
		return (z * z);
	}
	else {
		return (x * z * z);
	}
	return 0;
}