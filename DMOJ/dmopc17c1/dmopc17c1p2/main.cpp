#include <iostream>
using namespace std;

int main() {
    long N;
    long M;
    cin >> N;
    cin >> M;

    long crayons[N];

    long ltemp;
    for (long i = 1; i <= N; i++) {
        cin >> ltemp;
        crayons[i-1] = ltemp % M;
    }

    long ways = 0;
    long sum = 0;

    for (int f = 0; f < N; f++) {
        sum = 0;
        for (int l = f; l < N; l++) {
            sum += crayons[l];
            sum %= M;
            if (sum % M == 0) ways++;
        }
    }

    cout << ways << endl;

    return 0;
}