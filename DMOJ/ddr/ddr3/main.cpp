#include <bits/stdc++.h>

using namespace std;

bool visited[1000001];
vector<int> pathLen(1000001, 1000000);
vector<int> adj[1000001];

int minLen = 1000000;
int thisPath = 0;

int N, M;
int S, T;

void s(int node) {
    visited[node] = 1;
    if (thisPath >= pathLen[node]) return;
    else {
        pathLen[node] = thisPath;
    }

    // cout << "search: " << node << endl;

    if (node == T) {
        if (thisPath < minLen) {
            minLen = thisPath;
        }
        visited[T] = 0;
        return;
    }

    for (int nextNode : adj[node]) {
        if (!visited[nextNode]) {
            thisPath++;
            s(nextNode);
            thisPath--;
            visited[nextNode] = 0;
        }
    }

    return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    // shortest path from S to T
    // M - shortest path = answer

    cin >> N >> M;

    int x, y;
    for (int i = 1; i <= M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> S >> T;

    visited[S] = 1;
    s(S);

    cout << M-minLen << endl;

	return 0;
}
