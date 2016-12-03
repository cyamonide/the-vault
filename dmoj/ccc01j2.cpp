// (c) 2016 Cyamonide.
// 2016-12-02
// ccc01j2
// CCC '01 J2 - Mod Inverse

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x, m;
	cin >> x;
	cin >> m;

	int product;

	for (int n = 1; n < m; n++) {
		if ((x*n) % m == 1) {
			cout << n << endl;
			return 0;
		}
	}

	cout << "No such integer exists." << endl;

	return 0;
}
