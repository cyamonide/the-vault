// $ g++ -std=c++11 -O2 -Wall test.cpp -o test.out

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("p067_triangle.txt", "r", stdin);
	
	vector<int> lastRowSums;
	vector<int> thisRowSums;
	
	int root;
	scanf("%2d", &root);

	int itemp;

	for (int i = 1; i <= 2; i++) {
		scanf("%2d", &itemp);
		thisRowSums.push_back(itemp + root);
	}

	lastRowSums = thisRowSums;
	thisRowSums.clear();

	for (int j = 3; j <= 100; j++) {
		scanf("%2d", &itemp);
		thisRowSums.push_back(itemp + lastRowSums[0]);

		for (int i = 1; i < j-1; i++) {
			scanf("%2d", &itemp);
			thisRowSums.push_back(itemp + max(lastRowSums[i-1], lastRowSums[i]));
		}

		scanf("%2d", &itemp);
		thisRowSums.push_back(itemp + lastRowSums[j-2]);

		lastRowSums = thisRowSums;
		thisRowSums.clear();
	}

	int maxSum = 0;
	for (int a : lastRowSums) {
		if (a > maxSum) maxSum = a;
	}

	printf("%i\n", maxSum);
	
	return 0;
}