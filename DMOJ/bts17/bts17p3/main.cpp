#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double rmax(int ri) {
    if (ri % 2 == 1) {
        return ri + 0.4999999999;
    } else {
        return ri + 0.5;
    }
}

double rmin(int ri) {
    if (ri % 2 == 1) {
        return ri - 0.4999999999;
    } else {
        return ri - 0.5;
    }
}

int rround(double r) {
    if (r - static_cast<int>(r) == 0.5) {
        if (static_cast<int>(r) % 2 == 1) {
            return static_cast<int>(r) + 1;
        } else {
            return static_cast<int>(r);
        }
    }
    return round(r);
}

int main() {

    // rounded distances
    vector<int> r;
    // number of distances
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int itmp;
        cin >> itmp;
        r.push_back(itmp);
    }

    double max = 0;
    for (int a : r) {
        max += rmax(a);
    }

    double min = 0;
    for (int a : r) {
        min += rmin(a);
    }

    cout << rround(min) << endl << rround(max) << endl;

    return 0;
}