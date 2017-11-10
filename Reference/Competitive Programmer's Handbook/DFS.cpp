#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

vector<int> adj[6];
bool visited[6];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    cout << "Processed node " << s << endl;
    // process node s
    for (auto u : adj[s]) {
        dfs(u);
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

    dfs(1);

    return 0;
}
