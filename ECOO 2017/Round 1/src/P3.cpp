// ECOO Round 1
// (c) Victoria Park CI Team 1, 2017
// Eric Li, Simon Liu, Richard(Linyin) Sun, Andrew Wang
// P3 - Mountain View

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream fin;

int main() {

    /* File IO */
    fin.open("DATA32.txt");

    int mHeights[10002];
    int mCount[10002];

    for (int testCase = 1; testCase <= 10; testCase++) {

        int M = 0;
        fin >> M;

        // cout << M << endl;

        int itemp;

        for (int i = 1; i <= M; i++) {
            fin >> itemp;
            mHeights[i] = itemp;
        }

        /*
        for (int i = 0; i < 100; i++) {
            cout << mHeights[i] << " ";
        }
        */
        // cout << endl;

        for (int i = 1; i <= M; i++) {
            double doubleMax = mHeights[i + 1] - mHeights[i];
            mCount[i]++; mCount[i+1]++;
            for (int j = i+2; j <= M; j++) {
                double theta = (mHeights[j] - mHeights[i]) / (j-i*1.0);
                // cout << theta << endl;
                if (theta > doubleMax) {
                    doubleMax = theta;
                    mCount[i]++;
                    mCount[j]++;
                }
                // cout << theta << " ";
            }
            // cout << endl;
        }

        int ans = 0;

        int newMax = 0;
        for (int i = 1; i <= M; i++) {
            if (mCount[i] > newMax) {
                ans = i;
                newMax = mCount[i];
            }
        }

        cout << ans << endl;

        for (int i = 0; i < 10002; i++) {
            mHeights[i] = 0;
            mCount[i] = 0;
        }

    }

    return 0;
}
