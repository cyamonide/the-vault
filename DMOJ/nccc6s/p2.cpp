#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int q = n;

    int index;
    int length = 0;
    int c;

    for (int j = 0; j < q; j++) {
        for (int i = 1; i <= q; i++) {
            index = (j*q)+i;
            cin >> c;
            if (index != c) length++;
            if (length != 0 && index == c) {
                cout << length << "\n";
                return 0;
            }
        }
        if (length != 0) {
            cout << length << "\n";
            return 0;
        }
    }
    
    cout << 0 << "\n";

    return 0;
}