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


int Ci, Wi, So, Oo; // photo
int Si, Oi, Co, Wo; // respiration
int maxO = 0;

map<char, int>  p(map<char, int> a) {
    a['c'] -= Ci;
    a['w'] -= Wi;
    a['s'] += So;
    a['o'] += Oo;
    return a;
}

map<char, int>  r(map<char, int> a) {
    a['c'] += Co;
    a['w'] += Wo;
    a['s'] -= Si;
    a['o'] -= Oi;
    return a;
}

bool isValid(map<char, int> a) {
    if (a['c'] < 0) {
        return false;
    } else if (a['o'] < 0) {
        return false;
    } else if (a['w'] < 0) {
        return false;
    } else if (a['s'] < 0) {
        return false;
    }

    return true;
}

void mainloop(map<char, int> a) {
    if (isValid(a) && a['o'] > maxO) maxO = a['o'];
    if (!isValid(a)) return;

    mainloop(p(a));
    mainloop(r(a));

    return;
}

int main() {
    ifstream fin;
    fin.open("DATA11.txt");

    map<char, int> m;

    for (int query = 1; query <= 10; query++) {
        int C, O, W, S;
        fin >> C >> O >> W >> S;

        m['c'] = C;
        m['o'] = O;
        m['w'] = W;
        m['s'] = S;

        maxO = O;

        fin >> Ci >> Wi >> So >> Oo;
        fin >> Si >> Oi >> Co >> Wo;

        // brute force
        mainloop(m);

        cout << maxO << endl;
    }

    return 0;
}
