#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int N; // numbered cities
    int M; // bidirectional roads

    cin >> N;
    cin >> M;

    set<pair<int, int> > nodes;

    int n1;
    int n2;
    int dangerous;

    for (int i = 1; i <= M; i++) {
        cin >> n1 >> n2 >> dangerous;
        nodes.insert(make_pair(n1, n2));
        nodes.insert(make_pair(n2, n1));
    }

    queue<int> Q;
    bool visited[N+1] {0};
    int level[N+1] {-1};
    int finish = N;

    // starting point
    Q.push(1);
    visited[1] = 1;
    level[1] = 0;

    int parent;

    while (!Q.empty()) {

        parent = Q.front(); // set parent node

        Q.pop(); // remove parent node from queue

        for (int i = 1; i <= N; i++) {
            if (nodes.find(make_pair(parent, i)) != nodes.end() && !visited[i]) {
                Q.push(i);
                visited[i] = 1;
                level[i] = level[parent] + 1;
            }
        }

        if (visited[finish]) {
            cout << level[finish] << " " << level[finish] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}