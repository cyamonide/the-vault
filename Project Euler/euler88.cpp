// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

#include <bits/stdc++.h>

using namespace std;

vector<int> Nfactors;
bool found[12001] = {};
int foundSum = 0;
set<int> foundSet;

void factors(int a, int startFactor, int rootN) {
	for (int i = startFactor; i <= a; i++) {
		if (a % i == 0) {
			// successful
			Nfactors.push_back(i);
			factors(a/i, i, rootN);
		}
	}

	// product check
	int prod = 1;
	for (int b : Nfactors) prod *= b;

	if (prod == rootN && Nfactors.size() != 0 && Nfactors.size() != 1) {
		int k = rootN + Nfactors.size();
		for (int b : Nfactors) k -= b;

		if (k <= 12000 && found[k] == 0) {
			foundSum += 1;
			found[k] = 1;
			foundSet.insert(rootN);
		}
	}

	/*
	for (int b : Nfactors) {
		cout << b << " ";
	} cout << endl << endl;
	*/

	Nfactors.pop_back();
}

// find factors of number that multiply to N
// if sum of factors are less than N, add 1's accordingly
// this is always the case unless factors are 1 and N

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	found[0] = 1;
	found[1] = 1;

	for (int N = 4; foundSum < 11999; N++) {
		Nfactors.clear();
		// find all possible combinations of factors
		factors(N, 2, N); // always init with startFactor = 2;
	}

	// print sum
	int sum = 0;
	for (int a : foundSet) {
		sum += a;
	}

	cout << sum << endl;

	return 0;
}