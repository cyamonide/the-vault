#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

typedef long long ll;

using namespace std;

int counter = 0;
set<string> lexi[9];
vector<int> lens = {2, 3, 4, 5, 6, 8};

// sizes of words

void nextWord(string s) {
    if (s == "") {
        counter++;
        return;
    }
    // check for valid word
    for (int i : lens) {
        if (i > s.size()) return;
        if (lexi[i].find(s.substr(0, i)) != lexi[i].end()) {
            nextWord(s.substr(i, s.size()-i));
        }
    }
}

int main() {
    // ifstream fin;
    // fin.open("DATA11.txt");

    set<string> sttemp;

    sttemp = {"ug"};
    lexi[2] = sttemp;
    sttemp = {"ook", "oog"};
    lexi[3] = sttemp;
    sttemp = {"ooga", "mook", "ugug"};
    lexi[4] = sttemp;
    sttemp = {"oogam", "oogum"};
    lexi[5] = sttemp;
    sttemp = {"ookook"};
    lexi[6] = sttemp;
    sttemp = {"mookmook"};
    lexi[8] = sttemp;
    
    string stemp;
    for (int i = 1; i <= 10; i++) {
        counter = 0;
        cin >> stemp;
        nextWord(stemp);
        cout << counter << "\n";
    }

    return 0;
}