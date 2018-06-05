// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

#include <bits/stdc++.h>

using namespace std;

bool isPandigital(int a) {
	string s = to_string(a);

	if (s.length() != 9) return false;

	// if duplicate digits, not pandigital
	bool digits[9] = {0};

	for (char c : s) {
		if (digits[c-49] == 0) digits[c-49] = 1;
		else {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int maxPan = 918273645;

	// runs infinitely and prints new greater pandigital every time its found
	for (int i = 10; i >= 10; i++) {
		string s = to_string(i);
		if (s[0] != '9') continue;
		for (int j = 2; s.length() < 9; j++) {
			s = s + to_string(i*j);
		}
		if (s.length() != 9) continue;
		else if (isPandigital(stoi(s))) {
			if (stoi(s) > maxPan) {
				maxPan = stoi(s);
				cout << maxPan << endl;
			}
		}
	}
	
	return 0;
}