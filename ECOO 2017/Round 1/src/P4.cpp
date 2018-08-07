// ECOO Round 1
// (c) Victoria Park CI Team 1, 2017
// Eric Li, Simon Liu, Richard(Linyin) Sun, Andrew Wang
// P4 - Almost Sorted

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

ifstream fin;

int main() {
    /* File IO */
    fin.open("DATA42.txt");

    vector<pair<string, bool> > original;
    vector<pair<string, bool> > sorted;
    vector<pair<string, bool> > roriginal;
    vector<pair<string, bool> > rsorted;

    int numNames;

    for (int testCase = 1; testCase <= 10; testCase++) {
        fin >> numNames;

        string stemp;

        roriginal.clear();
        rsorted.clear();

        for (int i = 1; i <= numNames; i++) {
            fin >> stemp;
            roriginal.push_back(make_pair(stemp, false));
            rsorted.push_back(make_pair(stemp, false));
        }

        sort(rsorted.begin(), rsorted.end());

        int minSwaps = 1001;

        // remove individuals
        for (pair<string, bool> thisRemove : roriginal) {

            bool isBreak = false;

            for (int i = 0; i < roriginal.size(); i++) {
                if (roriginal[i].first == thisRemove.first && rsorted[i].first == thisRemove.first) {
                    isBreak = true;
                    break;
                }
            }
            if (isBreak) {
                continue;
            }

            // reinitialize vectors
            original = roriginal;
            sorted = rsorted;

            // removal
            for (pair<string, bool> a : original) {
                if (a.first == thisRemove.first) {
                    // erase remove idiom
                    original.erase(remove(original.begin(), original.end(), a));
                    break;
                }
            }
            // removal
            for (pair<string, bool> a : sorted) {
                if (a.first == thisRemove.first) {
                    sorted.erase(remove(sorted.begin(), sorted.end(), a));
                    break;
                }
            }

            /* DEBUG
            cout << "original:" << endl;
            for (pair<string, bool> a : original) {
                cout << a.first << endl;
            }
            cout << "sorted:" << endl;
            for (pair<string, bool> a : sorted) {
                cout << a.first << endl;
            } */

            vector<vector<string> > cycles;
            cycles.clear();

            // identifies cycles
            for (int i = 0; i < sorted.size(); i++) {
                if (original[i].second) { // checks if already visited
                    continue;
                } else if (original[i].first == sorted[i].first) {
                    original[i].second = true;
                    sorted[i].second = true;
                    vector<string> vtemp = {original[i].first, original[i].first};
                    cycles.push_back(vtemp);
                } else { // begins cycle

                    // temporary vector of cycles
                    vector<string> vtemp;
                    vtemp.clear();

                    // index to check in second element
                    int nextIndex = i;

                    // while the next element hasn't been visited
                    while (original[nextIndex].second == false) {
                        // adds first element to vtemp
                        vtemp.push_back(original[nextIndex].first);
                        original[nextIndex].second = true;
                        // add mirror element to vtemp
                        vtemp.push_back(sorted[nextIndex].first);
                        sorted[nextIndex].second = true;
                        // find index of element in original array
                        for (int j = 0; j < original.size(); j++) {
                            if (original[j].first == sorted[nextIndex].first) {
                                nextIndex = j;
                                break;
                            }
                        }
                    } // end of while next element not visited
                    cycles.push_back(vtemp);
                }
            } // end of cycle identification

            /* DEBUG
            for (vector<string> a : cycles) {
                for (string b : a) {
                    cout << b << " ";
                }
                cout << endl;
            } */

            if (numNames - 1 - cycles.size() < minSwaps) {
                minSwaps = numNames - 1 - cycles.size();
            }

            // DEBUG //
            // cout << numNames - cycles.size() - 1 << endl;
            // cout << cycles.size() << endl;

        }

        cout << minSwaps << endl;

    }

    return 0;
}
