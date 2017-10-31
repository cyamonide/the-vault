#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int R, C;
    cin >> R >> C;

    bool validr[R+1] = {0};
    bool validc[C+1] = {0};

    string stemp;
    for (int i = 1; i <= R; i++) {
        cin >> stemp;
        for (int j = 1; j <= C; j++) {
            if (stemp[j-1] == 'X') {
                validr[i] = true;
                validc[j] = true;
            }
        }
    }

    int Q;
    cin >> Q;

    int r, c;
    for (int i = 1; i <= Q; i++) {
        cin >> r;
        cin >> c;
        if (validr[c] || validc[r]) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}