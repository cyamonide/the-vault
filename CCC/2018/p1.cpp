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

double midPoint(int a, int b) {

    return a + abs((a - b)/2.0);
}   

int main() {

    int N;
    cin >> N;

    vector<int> road;
    int itemp;

    REP(i, 1, N) {
        cin >> itemp;
        // cout << itemp << " " << itemp + 1000000001 << endl;
        road.PB(itemp);
    }

    sort(road.begin(), road.end());

    // parse distances between villages
    
    vector<double> midPoints;
    REP(i, 1, N-1) {
        midPoints.PB(midPoint(road[i-1], road[i]));
    }
    
    double minDistance = midPoints[1] - midPoints[0];
    REP(i, 1, N-2) {
        if (midPoints[i] - midPoints[i-1] <= minDistance) {
            minDistance = midPoints[i] - midPoints[i-1];
        }
    }

    if (static_cast<int>(minDistance) == minDistance) {
        cout << minDistance << ".0" << endl;
    } else {
        cout << minDistance << endl;
    }

    return 0;
}