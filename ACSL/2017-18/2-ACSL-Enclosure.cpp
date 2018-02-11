#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <deque>

using namespace std;

/*
returns direction a bracket opens, true for right, false for left
*/
bool dir(char a) {
    if (a == '{' || a == '[' || a == '(') {
        return 1;
    } else {
        return 0;
    }
}

/*
returns complement of a bracket
*/
char complement(char a) {
    switch (a) {
        case '{':
            return '}';
        case '}':
            return '{';
        case '[':
            return ']';
        case ']':
            return '[';
        case '(':
            return ')';
        case ')':
            return '(';
        default:
            return a;
    }
}

/*
returns whether this character is a bracket or not
*/
bool isBracket(char a) {
    switch (a) {
        case '{':
        case '}':
        case '[':
        case ']':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

int main() {
    ifstream fin;
    fin.open("sr-test.txt");

    ofstream fout;
    fout.open("sr-out.txt");

    string sinput;

    map<char, int> bracePriority;
    bracePriority['{'] = 3;    bracePriority['}'] = 3;
    bracePriority['['] = 2;
    bracePriority[']'] = 2;
    bracePriority['('] = 1;
    bracePriority[')'] = 1;

    // main loop
    for (int mainloop = 1; mainloop <= 5; mainloop++) {

        // get line
        getline(fin, sinput);
        
        /*
        close bracket can occur immediately following:
        - an integer
        - another bracket
        NEVER after an operation

        search domain must be in between the matched bracket and the next matching bracket of the next matching bracket
        1. } find first bracket on the right
        2. locate matching bracket on the left
        3. search domain is between the lone bracket and matched bracket
        4. exclude any matched bracket sections in between

        */

        // parse input string with brackets, o's, and i's
        for (int i = 0; i < sinput.length(); i++) {
            switch(sinput[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    sinput[i] = 'i';
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    sinput[i] = 'o';
                    break;
            }
        }
        
        // look for unmatched bracket
        map<char, bool> exists;
        exists['{'] = false;
        exists['}'] = false;
        exists['['] = false;
        exists[']'] = false;
        exists['('] = false;
        exists[')'] = false;

        for (int i = 0; i < sinput.length(); i++) {
            // update exists map
            exists[sinput[i]] = true;
        }

        char missing; // character of missing bracket

        if (exists['{']^exists['}']) {
            if (exists['{']) missing = '}';
            else missing = '{';
        } else if (exists['[']^exists[']']) {
            if (exists['[']) missing = ']';
            else missing = '[';
        } else if (exists['(']^exists[')']) {
            if (exists['(']) missing = ')';
            else missing = '(';
        }

        // set of all indices to consider for insertion
        vector<int> validIndices;
        validIndices.clear();
        for (int i = 0; i <= sinput.length(); i++) validIndices.push_back(0);

        // DEBUG
        // cout << mainloop << ":" << endl;
        // DEBUG END

        for (int i = 0; i < sinput.length(); i++) {
            try {
                if (sinput[i-1] == 'i' && sinput[i] == 'i') continue;
            } catch (...) { }

            if (dir(missing)) { // right opening missing bracket
                // check if first case
                if (i == 0) {
                    validIndices[i] == true;
                    continue;
                }
                // check if its before an operator
                if (sinput[i] == 'o') continue;
            } else { // left opening missing bracket
                // check if it's going after an operator
                if (sinput[i-1] == 'o') continue;
            }

            validIndices[i] = true;
        }

        validIndices[sinput.length()] = true;

        // DEBUG display valid indices pass 1
        /*
        cout << sinput << endl;
        for (int i = 0; i < sinput.length(); i++) {
            if (validIndices[i]) cout << sinput[i];
            else cout << " ";
        } cout << endl;
        */

        for (int i = 0; i <= sinput.length(); i++) {
            // if not valid, continue
            if (!validIndices[i]) continue;

            // create new temp string
            string stest = sinput.substr(0, i) + missing + sinput.substr(i);
            // cout << stest << endl;

            // check for brace matching
            deque<char> bracketTracking;
            for (int j = 0; j <= sinput.length(); j++) {
                // cout << j << endl;
                // see if it's a bracket
                if (isBracket(stest[j])) {
                    // opening bracket, insert into deque
                    if (dir(stest[j])) {
                        if (bracketTracking.size() != 0 && bracePriority[stest[j]] > bracePriority[bracketTracking.back()]) {
                            validIndices[i] = false;
                            break;
                        }
                        bracketTracking.push_back(stest[j]);
                    }
                    // close bracket, must match top of deque
                    if (!dir(stest[j])) {
                        try {
                            if (bracketTracking.size() != 0 && complement(stest[j]) == bracketTracking.back()) {
                                validIndices[i] = true;
                                bracketTracking.pop_back();
                                continue;
                            } else {
                                validIndices[i] = false;
                                break;
                            }
                        } catch ( ... ) {
                            validIndices[i] = false;
                            break;
                        }
                    }
                }
            }

            // check if validIndices has been updated
            if (!validIndices[i]) continue;

            // check for lone integers
            for (int j = 0; j <= sinput.length(); j++) {
                if (stest[j] == missing || stest[j] == complement(missing)) { // if missing bracket
                    // search for matching bracket
                    for (int k = j+1; k <= sinput.length(); k++) {
                        if (stest[k] == 'o') break;
                        else if (stest[k] == missing || stest[k] == complement(missing)) {
                            validIndices[i] = false;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // print good indices
        for (int i = 0; i <= sinput.length(); i++) {
            if (validIndices[i]) {
                cout << i + 1;
                fout << i + 1;
                i++;
                for (; i <= sinput.length(); i++) {
                    if (validIndices[i]) {
                        cout << ", " << i + 1;
                        fout << ", " << i + 1;
                    }
                }
            }
        } cout << endl; fout << endl;

    }

    return 0;
}