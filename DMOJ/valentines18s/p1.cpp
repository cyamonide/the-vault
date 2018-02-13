#include <iostream>
#include <string>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

bool isPal(int a) {
    string f = to_string(a);
    string b = "";
    
    for (int i = f.length()-1; i >= 0; i--) {
        b += f[i];
    }

    if (f == b) {
        return true;
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    // less than M
    // greater than or equal to N

    int maxDist = 0; // trying to maximize this
    int output;

    int dist;
    int midPoint = N + (M-N)/2;

    REP(i, 0, (M-N)/2) {
        if (isPal(midPoint + i)) { // if palindrome
            cout << midPoint + i << endl;
            return 0;
        } else if (isPal(midPoint - i)) {
            cout << midPoint - i << endl;
            return 0;
        }
    }

    cout << output << endl;

    return 0;
}