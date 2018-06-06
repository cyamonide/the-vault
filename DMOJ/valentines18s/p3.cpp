#include <iostream>
#include <vector>
#include <deque>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;


int K, N;
// K is longest sub
// N is number of elements

vector<deque<int> > kLenSeqs;

vector<bool> used;

void genKLen(deque<int> a) {
    if (a.size() == K-1) {
        REP(i, a.back(), N) {
            if (!used[i]) {
                a.push_back(i);
                kLenSeqs.push_back(a);
                a.pop_back();
            }
        }
    } else {
        REP(i, a.back(), N) {
            if (!used[i]) {
                a.push_back(i);
                used[i] = true;
                genKLen(a);
                a.pop_back();
                used[i] = false;
            }
        }
    }

    return;
}

int main() {
    cin >> N >> K;

    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (N == 1 && K == 1) {
        cout << 1 << endl;
        return 0;
    }

    REP(i, 1, N) {
        used.PB(0);
    }
    used[0] = 1;
    
    // find all increasing with length K
    REP(i, 1, N) {
        used[i] = 1;
        genKLen({i});
        used[i] = 0;
    }

    cout << kLenSeqs.size() << endl;

    return 0;
}