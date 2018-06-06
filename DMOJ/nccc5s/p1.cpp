#include <iostream>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

int fact(int a) {
    int output = 1;
    REP (i, 1, a) {
        output *= i;
    }
    return output;
}

int choose(int a, int b) {
    return fact(a)/fact(a-b)/fact(b);
}

int main() {
    int N, X;

    cin >> N >> X;

    int cLower = 0;
    int cHigher = 0;
    int cEqual = 0;

    int itemp;

    REP (i, 1, N) {
        cin >> itemp;
        if (itemp > X) cHigher++;
        else if (itemp < X) cLower++;
        else cEqual++;
    }

    if (cEqual == 0) {
        cout << 0 << endl;
        return 0;
    }

    int setCount = 0;

    // non-identical upper and lower
    setCount += (cLower * cHigher * cEqual);

    if (cEqual != 1) {
        // identical left
        setCount += choose(cEqual, 2)*cHigher;
        // identical right
        setCount += choose(cEqual, 2)*cLower;
    }

    if (cEqual > 2) {
        // all identical
        setCount += choose(cEqual, 3);
    }

    cout << setCount << endl;

    return 0;
}