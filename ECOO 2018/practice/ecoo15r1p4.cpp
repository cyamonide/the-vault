#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

set<string> lexi = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
int counter = 0;

void kuklux(string s) {
    if (s[0] != 'u' && s[0] != 'o' && s[0] != 'm') return;

    REP(i, 0, 8) {
        string t = s.substr(0, i);
        // cout << t << endl;

        if (i == s.size()) {
            if (lexi.find(t) != lexi.end()) counter++;
            return;
        }

        if (lexi.find(t) != lexi.end()) { // if t is in lexicon
            // if i is size of s, end
            kuklux(s.substr(i, s.size() - i));
        }
    }
}

int main() {
    // ifstream fin;
    // fin.open("DATA11.txt");

    string stemp;
    REP(i, 0, 9) {
        counter = 0;
        cin >> stemp;
        kuklux(stemp);
        cout << counter << "\n";
    }

    return 0;
}