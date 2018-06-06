#include <iostream>
#include <vector>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

struct Deal {
    int cost = 0;
    vector<int> contents; // contents of deal
    bool used = false;
};


int M, N;
// quantity of each that must be purchased
vector<int> target;
// regular cost of orchid I
vector<int> costs;
// deals
vector<Deal> deals;

// minimum cost
int minCost;

void  mainLoop(int ongCost, vector<int> ongQty) {

    // if target reached, return
    if (ongQty == target) {
        if (ongCost < minCost) {
            minCost = ongCost;
            return;
        }
    }
    // if target exceeded, return
    REP(i, 0, N-1) {
        if (target[i] < ongQty[i]) {
            return;
        }
    }

    // go through deals
    REP(i, 0, M-1) {
        if (!deals[i].used) {
            deals[i].used = true;
            vector<int> dealQty = ongQty;
            REP(j, 0, N-1) { // add deal quantity to this quantity
                dealQty[j] += deals[i].contents[j];
            }
            mainLoop(ongCost + deals[i].cost, dealQty);
            deals[i].used = false;
        }
    }
    
    // residual cases
    REP(i, 0, N-1) {
        ongCost += costs[i]*(target[i]-ongQty[i]);
    }
    if (ongCost < minCost) {
        minCost = ongCost;
    }

    return;
}

int main() {
    cin >> N >> M;

    int itemp;
    REP(i, 1, N) {
        cin >> itemp;
        costs.PB(itemp);
    }

    REP(i, 1, M) {
        Deal dtemp;
        cin >> itemp;
        dtemp.cost = itemp;
        REP(j, 1, N) {
            cin >> itemp;
            dtemp.contents.PB(itemp);
        }
        deals.PB(dtemp);
    }

    REP(i, 1, N) {
        cin >> itemp;
        target.PB(itemp);
    }

    // calculate maximum min cost
    minCost = 0;
    REP(i, 0, N-1) {
        minCost += costs[i]*target[i];
    }

    // main loop
    REP(i, 0, M-1) {
        deals[i].used = true;
        mainLoop(deals[i].cost, deals[i].contents);
        deals[i].used = false;
    }

    cout << minCost << endl;

    return 0;
}