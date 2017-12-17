#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open ("billboard.out");
    ifstream fin;
    fin.open("billboard.in");

    int x1, y1, x2, y2;
    vector<pair<int, int> > r1, r2, truck; // [ [bottom left], [top right] ]

    fin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 999;
    y2 += 999;
    r1.push_back(make_pair(x1, y1));
    r1.push_back(make_pair(x1, y2));
    r1.push_back(make_pair(x2, y2));
    r1.push_back(make_pair(x2, y1));

    fin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 999;
    y2 += 999;
    r2.push_back(make_pair(x1, y1));
    r2.push_back(make_pair(x1, y2));
    r2.push_back(make_pair(x2, y2));
    r2.push_back(make_pair(x2, y1));

    fin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 999;
    y2 += 999;
    truck.push_back(make_pair(x1, y1));
    truck.push_back(make_pair(x1, y2));
    truck.push_back(make_pair(x2, y2));
    truck.push_back(make_pair(x2, y1));

    bool fov[2001][2001] = {{0}};

    for (int x = r1[0].first; x <= r1[2].first; x++) {
        for (int y = r1[0].second; y <= r1[2].second; y++) {
            fov[x][y] = 1;
        }
    }

    for (int x = r2[0].first; x <= r2[2].first; x++) {
        for (int y = r2[0].second; y <= r2[2].second; y++) {
            fov[x][y] = 1;
        }
    }

    for (int x = truck[0].first; x <= truck[2].first; x++) {
        for (int y = truck[0].second; y <= truck[2].second; y++) {
            fov[x][y] = 0;
        }
    }

    int a = 0;
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            a += fov[i][j];
        }
    }

    fout << a << "\n";
    cout << a << "\n";

    fout.close();

    return 0;
}