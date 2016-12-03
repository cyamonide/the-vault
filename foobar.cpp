// (c) 2016 Cyamonide.
// foobar.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	int itemp;
	for (int i = 1; i <= 10; i++) {
		cin >> itemp;
		a.push_back(itemp);
	}

	int b;
	cin >> b;

	int sum = 0;
	for (int i : a) {
		sum += i;
	}

	int M = sum;

	int m[M+10];

	for (int i = 0; i < M+10; i++) m[i]=0;

	m[0] = 1;

	for (int i = 0; i < 10; i++) {
		for (int j=M; j>=a[i]; j--) {
			m[j] |= m[j-a[i]];
		}
	}

	cout << m[b] << endl;

	return 0;
}
