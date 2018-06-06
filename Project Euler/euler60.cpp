// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

/*
Ran on c9.io workspace to brute force
*/

#include <bits/stdc++.h>
#include <chrono>
#include <set>

using namespace std;
using namespace std::chrono;

bool isPrime(long long test) {
	if (test == 2) return true;
	else {
		for (long long i = 2; i <= sqrt(test); i++) {
			if (test%i == 0) return false;
		}
		return true;
	}
}

long long combine(int a, int b) {
	string A = to_string(a);
	string B = to_string(b);
	return stoll(A+B);
}

bool areSubprimesValid(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (i == j) continue;
			if (!isPrime(combine(a[i], a[j]))) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	int upperBound = 7500;

	vector<int> primes;
	for (int i = 3; i <= upperBound; i++) {
		if (isPrime(i)) primes.push_back(i);
	}

	printf("primes generated until %d\n", upperBound);

	vector<vector<int> > doubles;

	// generate all subsets of two

	for (int i = 0; i < primes.size()-1; i++) {
		for (int j = i+1; j < primes.size(); j++) {
			if (areSubprimesValid({primes[i], primes[j]})) doubles.push_back({primes[i], primes[j]});
		}
	}

	printf("doubles generated\n");

	printf("doubles.size()=%d\n", doubles.size());

	vector<vector<int> > quads;

	for (int i = 0; i < doubles.size()-1; i++) {
		printf("i=%d of %d\n", i, doubles.size());
		for (int j = i+1; j < doubles.size(); j++) {
			set<int> a;
			for (int b : doubles[i]) a.insert(b);
			for (int b : doubles[j]) a.insert(b);

			if (a.size() != 4) continue;
			else {
				vector<int> c;
				for (int b : a) c.push_back(b);
				if (areSubprimesValid(c)) {
					quads.push_back(c);
				}
			}
		}
	}

	printf("quadruples generated\n");

	printf("quads.size()=%d\n", quads.size());

	/*
	for (vector<int> a : quads) {
		printf("%4d %4d %4d %4d\n", a[0], a[1], a[2], a[3]);
	}
	*/

	for (int i = 0; i < doubles.size(); i++) {
		for (int j = 0; j < quads.size(); j++) {
			set<int> a;
			for (int b : doubles[i]) a.insert(b);
			for (int b : quads[j]) a.insert(b);

			if (a.size() != 5) continue;
			else {
				vector<int> c;
				for (int b : a) c.push_back(b);
				if (areSubprimesValid(c)) {
					int sum = 0;
					for (int b : a) sum += b;
					printf("sum = %d\n", sum);
				}
			}
		}
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout << duration << endl;
	
	return 0;
}