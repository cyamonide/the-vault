#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>

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
            return ' ';
    }
}

int main() {
    ifstream fin;
    fin.open("2-ACSL-Enclosure.in");

    string sinput;

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

        // find index and character of root bracket
        pair<char, int> root;
        for (int i = 0; i < sinput.length(); i++) {
            if (sinput[i] == complement(missing)) {
                root = make_pair(complement(missing), i); // <bracket, index>
            }
        }

        // set of all indices to consider for insertion
        set<int> validIndices;
        int exclusion = 0;

        // rightward search
        if (dir(root.first)) {
            for (int i = root.second + 1; i < sinput.length(); i++) {
                // update exclusion period
                if (sinput[i] != 'o' && sinput[i] != 'i') {
                    if (dir(sinput[i])) {
                        exclusion++;
                    } else {
                        exclusion--;
                    }

                    // if exclusion was just decremented to zero, pass this one
                    if (exclusion == 0) continue;
                }

                // if not in a current exclusion period
                if (exclusion == 0) {
                    validIndices.insert(i);
                }

            }
        }
        // leftward search
        /*
        DEBUG: THIS SECTION ONWARDS DOES NOT WORK AND NEEDS RETHINKING
        */
        else {
            for (int i = root.second + 1; i >= 0; i--) {
                // update exclusion period
                if (sinput[i] != 'o' && sinput[i] != 'i') {
                    if (dir(sinput[i])) {
                        exclusion++;
                    } else {
                        exclusion--;
                    }

                    // if exclusion was just decremented to zero, pass this one
                    if (exclusion == 0) continue;
                }

                // if not in a current exclusion period
                if (exclusion == 0) {
                    validIndices.insert(i);
                }

            }
        }

    }

    return 0;
}