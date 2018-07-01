#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 5;
	int a[] = {2, 4, 3, 5, 1};

    // sort(a, a+n, greater<int>());
    sort(a, a+n, greater<int>());

    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }

	return 0;
}
