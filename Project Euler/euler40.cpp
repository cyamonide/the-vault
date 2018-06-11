// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long stringSize = 0;
	int prod = 1;
	string s = "";
	for (long long i = 1; stringSize <= 10000000; i++) {
		for (int j = 1; j <= to_string(i).length(); j++) {
			stringSize++;
			if (stringSize == 1 ||
				stringSize == 10 ||
				stringSize == 100 ||
				stringSize == 1000 ||
				stringSize == 10000 ||
				stringSize == 100000 ||
				stringSize == 1000000 ||
				stringSize == 10000000) {
					cout << to_string(i)[j-1] << endl;
					prod *= to_string(i)[j-1]-48;
			}
		}
	}

	cout << "product: " << prod << endl;

	return 0;
}