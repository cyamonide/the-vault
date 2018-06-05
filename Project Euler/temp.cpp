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

	char s[2];

	for (int j = 3; j <= 10; j++) {
		scanf("%2d", &itemp);
		cout << itemp << endl;

		for (int i = 1; i < j-1; i++) {
			scanf("%2d", &itemp);
			cout << itemp << endl;
		}

		scanf("%2d", &itemp);
		cout << itemp << endl;
	}
	
	return 0;
}