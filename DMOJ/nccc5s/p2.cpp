#include <iostream>
#include <vector>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> gifts;
    int itemp;
    REP(i, 1, N) {
        cin >> itemp;
        gifts.push_back(itemp);
    }

    // swap counter for bubble sort
    int swaps = 0;
    // swap in decreasing order
    bool doNextPass = true;
    while (doNextPass) {
        // next pass reset
        doNextPass = false;
        // if a swap is found, then next pass should be true
        REP(i, 0, N-2) {
            if (gifts[i] < gifts[i+1]) {
                itemp = gifts[i];
                gifts[i] = gifts[i+1];
                gifts[i+1] = itemp;
                swaps++;
                doNextPass = true;
            }
        }
    }

    cout << swaps << endl;

    return 0;
}