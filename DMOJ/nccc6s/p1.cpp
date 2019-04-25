#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        sum += c;
    }

    printf("%.1f\n", sum / n);

    return 0;
}