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
#include <math.h>

using namespace std;

/*
Problem 3
*/

typedef long long ll;
vector<int> prime;

bool isPrime(int i);

void genPrime() {
    prime.push_back(2);
    for (int i = 3; i < 1000000; i+= 2) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    reverse(prime.begin(), prime.end());
}

bool isPrime(int i) {
    if (i % 2 == 0) return false;

    for (int j = 3; j*j <= i; j+= 2) {
        if (i % j == 0) return false;
    }

    return true;
}

int main() {
    ifstream fin;
    fin.open("DATA31.txt");

    for (int query = 1; query <= 10; query++) {
        int N = 1, factor = 0, K, M;

        fin >> K >> M;

        // largest prime dividing K
        int t;
        int i = 0;
        bool found = false;

        genPrime();

        while (!found) {
            if (i >= prime.   size()) {
                t = K;
                break;
            }
            if (K % prime[i] == 0) {
                found = true;
                t = prime[i];
            }
            i++;
        }

        bool reached = false;
        int q= 0;
        while (!reached) {
            if (K % t == 0) {
                K /= t;
                q++;
            } else reached = true;
        }
        // cout << "this is q" << q << endl;

        // if (query == 4) cout << "nobba:" << t << endl;

        while (factor < q*M) {
            int j = 1;
            while(pow(t, j) <= N) {
                if (remainder((double)(N), pow(t, j)) == 0) factor++;
                              // N%static_cast<int>(pow(t, j)+0.1) == 0) factor++;
                j++;
            }
            // cout << N << " " << factor << " " << M << endl;
            if (factor >= q*M) {
                // cout << N << " " << M << " " << factor << endl;
                break;
            }
            N++;
        }
        // cout << "EHUGH " << factor << " " << M << endl;
        cout << N << endl;
    }

    return 0;
}
