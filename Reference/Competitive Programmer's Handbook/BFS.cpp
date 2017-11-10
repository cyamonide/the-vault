#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

vector<int> adj[6];

void bfs(int x) {

    queue<int> q;
    int distance[6] = {0};
    bool visited[6] = {0};

    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            cout << "Visited node " << u << endl;
            distance[u] = distance[s]+1;
            cout << distance[u] << endl;
            q.push(u);
        }
    }

    for (int i = 1; i < 6; i++) {
        cout << "Node: " << i << " | Distance: " << distance[i] << endl;
    }
}

void undadd(int s, int r) {
    adj[s].push_back(r);
    adj[r].push_back(s);
}

int main() {

    undadd(1, 2);
    undadd(1, 4);
    undadd(2, 3);
    undadd(3, 5);
    undadd(2, 5);

    bfs(1);

    return 0;
}
