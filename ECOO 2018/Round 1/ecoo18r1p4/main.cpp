#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
Problem 4
*/

vector<pair<long long, long long> > p;
vector<long long> fibs; // fib[n] is nth fib number

/*
returns nth fibonacci number
*/
long long fib(long long n) {
    long long a = 1;
    long long b = 1;
    long long temp;
    if (n <= 2) {
        return 1;
    }
    for (long long i = 3; i <= n; i++) {
        temp = b;
        b += a;
        a = temp;
    }
    return b;
}

/*
returns which fib a coordinate is in
*/
long long check(long long x, long long y) {
    long long cx, cy;
    for (long long i = 1; i <= 92; i++) {
        cx = p[i].first;
        cy = p[i].second;
        // check if x coordinate is outside of this range
        if (x < cx || x > cx+fibs[i]) continue;
        // similarly, for y
        if (y > cy || y < cy-fibs[i]) continue;
        // return nth fib number if valid
        return i;
    }

    cout << "FUCK IT DIDN'T WORK!" << endl;
    return 0;
}

int main() {
    ifstream fin;
    fin.open("DATA42.txt");

    /* generate fib numbers */
    fibs.push_back(0);
    for (long long i = 1; i <= 92; i++) {
        fibs.push_back(fib(i));
    }

    /* corner generation */
    p.push_back(make_pair(0, 0));
    p.push_back(make_pair(0, 0));
    // generate corners
    long long minx = 0;
    long long maxy = 0;
    long long miny = -1;
    for (long long i = 1; i <= 91; i++) {
        if (i % 4 == 1) {
            // left
            pair<long long, long long> next;
            next.first = minx - fibs[i+1];
            minx -= fibs[i+1];
            next.second = maxy;
            p.push_back(next);
        } else if (i % 4 == 2) {
            // up
            pair<long long, long long> next;
            next.first = minx;
            next.second = maxy+fibs[i+1];
            maxy += fibs[i+1];
            p.push_back(next);
        } else if (i % 4 == 3) {
            // right
            pair<long long, long long> next;
            next.first = minx+fibs[i];
            next.second = maxy;
            p.push_back(next);
        } else {
            // down
            pair<long long, long long> next;
            next.first = minx;
            next.second = miny;
            miny -= fibs[i+1];
            p.push_back(next);
        }
    }

    for (long long query = 1; query <= 10; query++) {
        long long xtemp, ytemp;
        fin >> xtemp >> ytemp;

        cout << check(xtemp, ytemp) << endl;
    }

    return 0;
}
