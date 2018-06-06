#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
Problem 2
*/

int main() {
    ifstream fin;
    fin.open("DATA22.txt");

    for (int query = 1; query <= 10; query++) {
        int n;
        fin >> n;
        int id, r;
        int itemp;
        vector<priority_queue<int, vector<int>, greater<int> > > q;
        vector<int> ids;
        for (int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int> > qtemp;
            fin >> id;
            fin >> r;
            for (int j = 0; j < r; j++) {
                fin >> itemp;
                qtemp.push(itemp);
            }
            q.push_back(qtemp);
            ids.push_back(id);
        }

        // look for smallest ra
        int minr = q[0].top();
        for (int i = 1; i < n; i++) {
            if (q[i].top() < minr) {
                minr = q[i].top();
            }
        }

        vector<int> valid;
        for (int i = 0; i < n; i++) {
            if (q[i].top() == minr) {
                valid.push_back(ids[i]);
            }
        }

        sort(valid.begin(), valid.end());

        cout << minr << " {";
        if (valid.size() == 1) {
            cout << valid[0] << "}" << endl;
        } else {
            cout << valid[0];
            for (int i = 1; i < valid.size(); i++) {
                cout << "," << valid[i];
            }
            cout << "}" << endl;
        }
    }

    return 0;
}
