#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> parse(string s) {
    vector<string> output;

    string thisWord;

    for (char c : s) {
        if (c != ' ') {
            thisWord += c;
        } else {
            output.push_back(thisWord);
            thisWord = "";
        }
    }

    output.push_back(thisWord);

    return output;
}

int main() {

    for (int query = 1; query <= 10; query++) {
        int w;
        cin >> w;
        string input;
        ws(cin);
        getline(cin, input);

        vector<string> t = parse(input);
        vector<string> thisLine;

        for (string thisWord : t) {
            // check if single word exceeds w
            if (thisLine.size() == 1) {
                if (thisLine[0].length() > w) {
                    string thisWord1 = thisLine[0];
                    while (thisWord1.length() > w) {
                        cout << thisWord1.substr(0, w) << endl;
                        thisWord1 = thisWord1.substr(w, thisWord1.length()-w);
                    }
                    if (thisWord1.length() == w) {
                        cout << thisWord1 << endl;
                        continue;
                    } else {
                        thisLine.clear();
                        thisLine.push_back(thisWord1);
                    }
                }
            }

            // append thisWord to thisLine
            thisLine.push_back(thisWord);

            // check if thisLine's length exceeds w
            int thisLen = -1;
            for (string a : thisLine) {
                thisLen += a.length();
                thisLen++;
            }
            if (thisLen >= w) { // if longer than w, pop, print, and restart next line
                if (thisLen > w) thisLine.pop_back();
                for (string a : thisLine) {
                    cout << a << " ";
                }
                if (thisLine.size() != 0) cout << endl;
                thisLine.clear();
                if (thisLen > w) {
                    thisLine.push_back(thisWord);
                }
            }
        }

        if (thisLine.size() == 1 && thisLine[0].length() > w) {
            string thisWord1 = thisLine[0];
            while (thisWord1.length() > w) {
                cout << thisWord1.substr(0, w) << endl;
                thisWord1 = thisWord1.substr(w, thisWord1.length() - w);
            }
            if (thisWord1.length() <= w) {
                cout << thisWord1 << endl;
            } else {
                thisLine.clear();
            }
        } else if (thisLine.size() != 0){
            for (string a : thisLine) {
                cout << a << " ";
            } cout << endl;
        }

        cout << "=====" << endl;
    }

    return 0;
}