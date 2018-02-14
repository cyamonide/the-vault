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

int factors(int N) {
    int output = 0;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N%i == 0) {
            output += 2;
        }
    }

    // if perfect square ,subtract one
    if (pow(sqrt(N), 2) == N) {
        output--;
    }

    return output;
}

struct Foobar {
    int foobat = 0;
};

int main() {
    int N;
    cin >> N;

    cout << factors(N) << endl;

    // at least 2 subtrees
    

    return 0;
}