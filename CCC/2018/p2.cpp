#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

struct Foobar {
    int foobat = 0;
};

int main() {
    int N;
    cin >> N;

    int itemp;
    vector<vector<int> > table;
    vector<int> vtemp;

    REP(i, 1, N) {
        REP(j, 1, N) {
            cin >> itemp;
            vtemp.PB(itemp);
        }
        table.PB(vtemp);
        vtemp.clear();
    }

    // find which ways are strictly decreasing
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;

    // or find minimum of the corners

    // find if left is decreasing
    if (table[0][0] - table[0][1] > 0) {
        right = true;
    } else {
        left = true;
    }

    // up/down
    if (table[0][0] - table[1][0] > 0) {
        down = true;
    } else {
        up = true;
    }

    // cout << down << up << left << right;

    pair<int, int> root;
    // find root element
    if (up && left) {
        root = MP(0, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << table[i][j] << " ";
            } cout << endl;
        }

    } else if (up && right) {
        root = MP(0, N-1);

        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                cout << table[j][i] << " ";
            } cout << endl;
        }

    } else if (down && left) {
        root = MP(N-1, 0);

        for (int i = 0; i < N; i++) {
            for (int j = N-1; j >= 0; j--) {
                cout << table[j][i] << " ";
            } cout << endl;
        }

    } else if (down && right) {
        root = MP(N-1, N-1);

        for (int i = N-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                cout << table[i][j] << " ";
            } cout << endl;
        }
    }

    // cout << root.F << " " << root.S << endl;
    // cout << table[root.F][root.S] << endl;

    return 0;
}