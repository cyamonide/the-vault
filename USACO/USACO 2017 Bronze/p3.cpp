#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ofstream fout;
    fout.open ("measurement.out");
    ifstream fin;
    fin.open("measurement.in");
    
    int n;
    fin >> n;

    vector<tuple<int, char, int> > journal;

    int day;
    string stemp;
    char name;
    int delta;

    for (int i = 1; i <= n; i++) {
        fin >> day;
        fin >> stemp;
        name = stemp[0];
        fin >> stemp;
        delta = stoi(stemp.substr(1, stemp.length()-1));
        if (stemp[0] == '-') delta *= -1;
        journal.push_back(make_tuple(day, name, delta));
    } // get journal

    sort(journal.begin(), journal.end());

    // previous set of winners
    set<int> lastA;
    lastA.insert('B');
    lastA.insert('E');
    lastA.insert('M');
    set<int> thisA;
    // map of current milk output
    map<int, int> current;
    current['B'] = 7;
    current['E'] = 7;
    current['M'] = 7;

    int output = 0;

    for (int i = 0; i < n; i++) {
        cout << get<2>(journal[i]) << " ";
    } cout << endl;

    for (int i = 0; i < n; i++) {

        cout << i << endl;

        char q = get<1>(journal[i]);
        current[q] = current[q] + get<2>(journal[i]); // do delta

        cout << static_cast<char>(q) << " " << current[q] << endl;

        if (i != n-1 && get<0>(journal[i]) == get<0>(journal[i+1])) {
            continue;
        } else {
            // see if there's a change
            int mx = max(current['B'], max(current['E'], current['M']));
            
            if (current['B'] == mx) thisA.insert('B');
            if (current['E'] == mx) thisA.insert('E');
            if (current['M'] == mx) thisA.insert('M');

            for (int a : thisA) {
                cout << static_cast<char>(a) << " ";
            } cout << endl;
            for (int a : lastA) {
                cout <<  static_cast<char>(a) << " ";
            } cout << endl;

            // if there's a change in output
            if (thisA != lastA) output += 1;

            lastA = thisA;

            thisA.clear();
        }

    }

    fout << output << "\n";
    cout << output << endl;

    fout.close();

    return 0;
}