#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    bool DEBUG = false;

    string PROBLEM_ID = "measurement";
    ifstream fin;
    fin.open(PROBLEM_ID + ".in");
    ofstream fout;
    fout.open(PROBLEM_ID + ".out");

    int n;
    fin >> n;

    int G;
    fin >> G;

    vector<tuple<int, int, int> > journal;

    int day;
    string stemp;
    int id;
    int delta;

    for (int i = 1; i <= n; i++) {
        fin >> day;
        fin >> id;
        fin >> stemp;
        delta = stoi(stemp.substr(1, stemp.length()-1));
        if (stemp[0] == '-') delta *= -1;
        journal.push_back(make_tuple(day, id, delta));
    } // get journal
    
    sort(journal.begin(), journal.end());

    // DEBUG display journal
    if (DEBUG) {
        cout << "JOURNAL:" << endl;
        for (auto i : journal) {
            tie(day, id, delta) = i;
            cout << day << " " << id << " " << delta << endl;
        }
        cout << "-----" << endl;
    }

    // current max
    map<int, int> byOutput; // max value, number of cows at this max value
    byOutput[G] = 200000;

    // byOutput.rbegin()->second
    
    // map of current milk output // all initialized to zero
    map<int, int> current;

    // cases
    bool case1, case2, case3;

    int changes = 0;

    pair<int, int> lastTop =  make_pair(G, byOutput[G]);

    // map of lone cow ID's by output value
    map<int, int> loneCows;

    int lastLoneCow = 0;

    for (int q = 0; q < n; q++) {

        tie (day, id, delta) = journal[q];

        // DEBUG: day output
        if (DEBUG) cout << "day:" << day << endl;

        // instantiate to G if necessary
        if (current[id] == 0) current[id] = G;

        // remove from original output classification
        byOutput[current[id]]--;
        // lone cow
        if (byOutput[current[id]] == 1) {
            loneCows[current[id]] = id;
        } else {
            loneCows[current[id]] = 0;
        }

        // if this output classification is zero, then delete from map
        /* if (byOutput[current[id]] == 0) {
            auto it = byOutput.begin();
            for (int i = 1; i < byOutput.size(); i++) {
                it++;
            }
            byOutput.erase(it);
        } */
 
        current[id] += delta; // do delta
        
        // add to new output classification
        byOutput[current[id]]++;
        // lone cow
        if (byOutput[current[id]] == 1) {
            loneCows[current[id]] = id;
        } else {
            loneCows[current[id]] = 0;
        }

        // check for changes in top milk producer
        auto it = byOutput.rbegin();

        // generate iterator for this top output
        int thisTopOutput = it->first;
        int thisTopOutputCount = it->second;
        while (thisTopOutputCount == 0) {
            it++;
            thisTopOutput = it->first;
            thisTopOutputCount = it->second;
        }

        // if this original output was first, and new output is also first
        if (thisTopOutputCount == 1 && lastTop.second == 1) {
            if (current[id]-delta == lastTop.first && current[id] == thisTopOutput) {
                // do nothing
            } else {
                if (thisTopOutput != lastTop.first || thisTopOutputCount != lastTop.second) {
                    changes++;
                }
            }
        } else {
            if (thisTopOutput != lastTop.first || thisTopOutputCount != lastTop.second) {
                changes++;
            }
        }

        // lone cow cases

        /* if (thisTopOutputCount == 1 && loneCows[thisTopOutput] != lastLoneCow) { // set up last lone cow
            if (DEBUG) cout << "lone cow setup" << endl;
            lastLoneCow = id;

            // all other cases
            if (thisTopOutput != lastTop.first || thisTopOutputCount != lastTop.second) {
                changes++;
            }
        } else if (thisTopOutputCount == 1 && loneCows[thisTopOutput] == lastLoneCow) { // test if this top lone cow was the last one
            if (DEBUG) cout << "lone cow" << endl;
        } else { // reset last lone cow
            lastLoneCow = 0;
            if (DEBUG) cout << "non lone cow" << endl;

            // all other cases
            if (thisTopOutput != lastTop.first || thisTopOutputCount != lastTop.second) {
                changes++;
            }
        } */
        
        lastTop = make_pair(thisTopOutput, thisTopOutputCount);

        if (DEBUG) {

            cout << "changes:" << changes << endl;

            // DEBUG print byOutput
            
            cout << "iteration: " << q << endl;
            for (auto i : byOutput) {
                cout << i.first << " " << i.second << endl;
            } cout << "-----------" << endl;

            // DEBUG print this output
            
            cout << "this top:" << endl;
            cout << thisTopOutput << " " << thisTopOutputCount << endl;
            cout << "----------" << endl << endl;
        }
        
    }

    fout << changes << "\n";
    cout << changes << endl;

    fout.close(); return 0;
}