#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

using namespace std;

/*
Problem 2
*/

int main() {
    ifstream fin;
    fin.open("DATA22.txt");

    for (int query = 1; query <= 10; query++) {
        int N;
        fin >> N;

        int D;
        double W;
        map<int, vector<double> > m;
        vector<double> vtemp;

        vector<pair<int, double> > l;
        l.clear();

        for (int q = 1; q <= N; q++) {
            fin >> D >> W;
            // append to list
            m[D].push_back(W);
            l.push_back(make_pair(D, W));
        }

        sort(l.begin(), l.end());
        reverse(l.begin(), l.end());

        /*
        for (pair<int, double> a : l) {
            cout << a.first << " " << a.second << endl;
        }
        */

        // set current day to max day
        int thisDay;
        thisDay = l[0].first;

        double ongSum = 0;

        int fuck = 0;

        while (thisDay > 0 && l.size() > 0) {
            // find largest weight with day greater than or equal to current day
            double largestWeight = 0;
            int targetIndex = 0;
            // continue
            if (l[0].first < thisDay) {
                    thisDay--;
                    continue;
            }
            for (int i = 0; i < l.size(); i++) {
                if (l[i].first < thisDay) break;
                if (l[i].second > largestWeight) {
                    targetIndex = i;
                    largestWeight = l[i].second;
                }
            }
            // now have the index of target project
            ongSum += l[targetIndex].second;

            // cout << "day:" << thisDay << " target: " << l[targetIndex].first << " " << l[targetIndex].second << endl;
            fuck++;
            // printf("%.10f\n", l[targetIndex].second);

            // remove from l
            l.erase(remove(l.begin(), l.end(), l[targetIndex]));

            /*
            cout << "---" << endl;
            for (pair<int, double> a : l) {
                cout << a.first << " " << a.second << endl;
            }
            cout << "---" << endl;
            */

            thisDay--;
        }

        // cout << fuck << endl;

        printf("%.4f\n", ongSum);
        // printf("%.15f\n", ongSum/1000.0);
        // cout << ongSum << endl;
    }

    return 0;
}
