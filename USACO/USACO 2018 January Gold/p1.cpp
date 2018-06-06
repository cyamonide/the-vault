#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

// create graph
vector<pair<int, long>> adj[100001]; // vertex and edge weight
bool visited[100001];
long k;
int v;
int count;

void dfs(int a) {
    visited[a] = true;
    for (auto relations : adj[a]) {
        cout << relations.first << " " << relations.second << " " << k << endl;
        if (visited[relations.first]) continue;
        else {
            cout << "search" << relations.first << endl;
            // check if satisfies k
            if (relations.second < k) continue;
            else {
                count++;
                dfs(relations.first);
            }
        }
    }

    
    visited[a] = 0;

    return;
}

int main() {
    ofstream fout;
    fout.open ("mootube.out");
    ifstream fin;
    fin.open("mootube.in");

    // N videos
    // N-1 connections
    // each video can be reached from another video ONE way

    int N, Q; // N - number of videos, Q - number of questions
    fin >> N >> Q;

    vector<tuple<int, int, long> > pairs; // p, q, and relationship r

    int ptemp, qtemp;
    long rtemp;
    for (int i = 1; i <= N-1; i++) {
        fin >> ptemp >> qtemp >> rtemp;

        adj[ptemp].push_back(make_pair(qtemp, rtemp));
        adj[qtemp].push_back(make_pair(ptemp, rtemp));
    }

    // FJ's questions
    for (int q = 0; q < Q; q++) {
        fin >> k >> v;
        count = 0;

        dfs(v);
        
        cout << count << endl << endl;
        fout << count << endl;
    }
 
    fout.close();

    return 0;
}