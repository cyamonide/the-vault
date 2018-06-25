#include <bits/stdc++.h>

using namespace std;

bool isOpposite(char a, char b) {
    if (a == 'U' && b == 'D') return true;
    if (a == 'D' && b == 'U') return true;
    if (a == 'L' && b == 'R') return true;
    if (a == 'R' && b == 'L') return true;
    return false;
}

bool isDistinct(string a) {
    map<char, bool> b;
    b['U'] = 0;
    b['D'] = 0;
    b['L'] = 0;
    b['R'] = 0;

    for (char c : a) {
        if (b[c] == 1) return false;
        b[c] = 1;
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    string seq;
    cin >> seq;

    if (!isDistinct(seq)) {
        cout << "Neither" << endl;
        return 0;
    }

    if (!isOpposite(seq[0], seq[2])) {
        cout << "Neither" << endl;
        return 0;
    }

    if (seq[0] == 'L' || seq[0] == 'R') {
        cout << "Crossover" << endl;
    } else {
        cout << "Candle" << endl;
    }

	return 0;
}
