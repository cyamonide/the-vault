#include<iostream>
#include<vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> trees;
    trees.push_back(0);
    int m;
    cin >> m;
    int ongoing = m;
    trees.push_back(m);
    for (int i = 2; i <= N; i++) {
        cin >> m;
        ongoing += m;
        trees.push_back(ongoing);
    }
    
    long long q;
    cin >> q; // queries

    for (long long i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << trees[b+1]-trees[a] << "\n";
    }

    return 0;
}