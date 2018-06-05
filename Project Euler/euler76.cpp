// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

#include <bits/stdc++.h>

using namespace std;

int onSum = 0;

void add(int thisSum, int toAdd) {
	// add from 1 to the last number added
	if (thisSum + toAdd == 100) {
		onSum++;
		return;
	} else if (thisSum + toAdd > 100) {
		return;
	}
	
	for (int q = 1; q <= toAdd; q++) {
		add(thisSum + toAdd, q);
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= i && j <= 100-i; j++) {
			add(i, j);
		}
	}

	printf("%i\n", onSum);
	
	return 0;
}