#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int INF = 2147483647;

int main () {
    int r, c;
    string thisRow;

    cin >> r >> c;
    vector<pair<int, int> > adj[r][c];
    for (int i = 0; i < r; i++) {
        cin >> thisRow;
        for (int j = 0; j < thisRow.size(); j++) {
            char thisChar = thisRow[j];
            if (thisChar == '+') {
                if (j-1 >= 0) { try { adj[i][j].push_back(make_pair(i, j-1)); } catch (...) {} }
                if (j+1 < c) { try { adj[i][j].push_back(make_pair(i, j+1)); } catch (...) {} }
                if (i-1 >= 0) { try { adj[i][j].push_back(make_pair(i-1, j)); } catch (...) {} }
                if (i+1 < r) { try { adj[i][j].push_back(make_pair(i+1, j)); } catch (...) {} }
            } else if (thisChar == '|') {
                if (i+1 < r) { try { adj[i][j].push_back(make_pair(i+1, j)); } catch (...) {} }
                if (i-1 >= 0) { try { adj[i][j].push_back(make_pair(i-1, j)); } catch (...) {} }
            } else if (thisChar == '-') {
                if (j-1 >= 0) { try { adj[i][j].push_back(make_pair(i, j-1)); } catch (...) {} }
                if (j+1 < c) { try { adj[i][j].push_back(make_pair(i, j+1)); } catch (...) {} }
            }
        }
    }

    // adj now contains an adjacency list of the graph

    // perform BFS on the graph to find shortest path
    int distance[r][c]; // distances
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            distance[i][j] = 0;
        }
    }
    bool visited[r][c]; // whether or not this node has been visited
    queue<pair<int, int> > q; // queues to process
    distance[0][0] = 0;
    visited[0][0] = 1;
    q.push(make_pair(1, 1));
    while(!q.empty()) {
        pair<int, int> s = q.front(); q.pop();
        for (pair<int, int> u : adj[s.first][s.second]) {
            if (visited[u.first][u.second]) { continue; }
            distance[u.first][u.second] = distance[s.first][s.second]+1;
            visited[u.first][u.second] = true;
            q.push(u);
        }
    }

    if (distance[r][c] == 0) {
            cout << -1 << endl;
    } else {
        cout << distance[r][c] << endl;
    }


    // debug output
    /*
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vector<pair<int, int> > tmp = adj[i][j];
            cout << "Node " << j << " " << i << endl;
            for (pair<int, int> a : tmp) {
                cout << a.first << " " << a.second << " , ";
            }
            cout << endl;
        }
    }
    */

    return 0;
}
