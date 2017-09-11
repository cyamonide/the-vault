#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double rmax(long long ri) {
    if (ri % 2 == 1) {
        return 0.499999999999;
    } else {
        return 0.5;
    }
}

double rmin(long long ri) {
    if (ri % 2 == 1) {
        return -0.499999999999;
    } else {
        return -0.5;
    }
}

long long rround(double r) {
    if (r - static_cast<long long>(r) == 0.5) { // if in between
        if (static_cast<long long>(r) % 2 == 1) { // if odd round up
            return static_cast<long long>(r) + 1;
        } else { // if even round down
            return static_cast<long long>(r);
        }
    }
    return round(r);
}

int main() {

    // rounded distances
    vector<long> r;
    // number of distances
    long long N;
    cin >> N;
    for (long long i = 1; i <= N; i++) {
        long long itmp;
        cin >> itmp;
        r.push_back(itmp);
    }

    int odds = 0;
    int evens = 0;
    long long sum = 0;
    for (long long i : r) {
      sum += i;
      if (i % 2 == 1) odds++;
      else evens++;
    }



    double max = 0;
    max += odds * 0.499;
    max += evens * 0.5;

    double min = 0;
    min -= odds * 0.499;
    min -= evens * 0.499;

    cout << rround(sum + min) << endl << rround(sum + max) << endl;

    return 0;
}
