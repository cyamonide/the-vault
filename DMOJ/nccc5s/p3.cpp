#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (auto i = a; i <= b; i++)

typedef long long ll;

using namespace std;

// original adjacency list
vector<int> adjO[51];
vector<int> adj[51];
bool visited[51];

void DFS(int thisNode, int target) {
    if (thisNode == target) {
        visited[thisNode] = true;
        return;
    }
    if (visited[thisNode]) return;
    visited[thisNode] = true;
    // find next nodes to DFS
    for (auto a : adj[thisNode]) {
        DFS(a, target);
        if (visited[target]) return;
    }
}

int main() {

    int N, M;
    cin >> N >> M;

    // Carol wishes to get to airport N

    vector<pair<int, int> > indexedFlights;

    int i1, i2;
    REP(i, 1, M) {
        cin >> i1 >> i2;
        adjO[i1].PB(i2);
        
        indexedFlights.PB(MP(i1, i2));
    }
    // original adjacency list created

    REP(i, 0, M-1) {
        REP(j, 1, 50) {
            adj[j] = adjO[j];
        }
        //cout << "rEP done" << endl;
        // remove the ith flight
        int pFrom = indexedFlights[i].F;
        int pTo = indexedFlights[i].S;
        //cout << "init" << endl;
        adj[pFrom].erase(remove(adj[pFrom].begin(), adj[pFrom].end(), pTo));

        // perform DFS
        //cout << "DFSing" << endl;
        DFS(1, N);
        //cout << "DFS complete" << endl;
        // check if target is visited
        if (visited[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        /*
        // show array
        REP(k, 0, M) {
            cout << k << ": ";
            for (auto a : adj[k]) {
                cout << a << " ";
            } cout << endl;
        }
        */

        // reset visited array
        REP(j, 0, 50) visited[j] = 0;
    }

    return 0;
}