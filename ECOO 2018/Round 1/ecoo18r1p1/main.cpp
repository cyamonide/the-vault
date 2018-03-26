#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

using namespace std;

/*
Problem 1
*/

int main() {
    ifstream fin;
    fin.open("DATA11.txt");

    for (int query = 1; query <= 10; query++) {
        int t, n;
        fin >> t;
        fin >> n;
        vector<bool> days;
        char ctemp;

        // vector of bools for the days she comes back with a box
        for (int i = 0; i < n; i++) {
            fin >> ctemp;
            if (ctemp == 'E') {
                days.push_back(false);
            } else if (ctemp  == 'B') {
                days.push_back(true);
            }
        }

        int buffer = 0;
        for (int i = 0; i < n; i++) {
            if (days[i]) {
                buffer += t;
            }
            if (buffer != 0) {
                buffer--;
            }
        }

        cout << buffer << endl;
    }

    return 0;
}
