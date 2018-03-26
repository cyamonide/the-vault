#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
Problem 3
*/

int n, x, y, z;

string convert(string s) {
    string comp[102];
    for (int i = 0; i < s.length(); i++) {
        comp[i] = to_string((int)(s.at(i))-48);
    }

    for (int i = 0; i < s.length(); i++) {
        if (comp[i] == "0") comp[i] = to_string(z);
        else if (stoi(comp[i]) % 2 == 0) { // if even
            int temp;
            temp = stoi(comp[i]);
            temp += x;
            comp[i] = to_string(temp);
        } else {
            int temp;
            temp = stoi(comp[i]);
            temp -= y;
            if (temp < 0) temp = 0;
            comp[i] = to_string(temp);
        }
    }

    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        ans += comp[i];
    }
    return ans;
}

int main() {
    ifstream fin;
    fin.open("DATA32.txt");

    for (int query = 1; query <= 10; query++) {
        fin >> n >> x >> y >> z;

        vector<string> v;
        for (int j= 0; j < n; j++) {
            string s;
            fin >> s;
            v.push_back(s);
        }

        for (int j = 0; j < n; j++) {
            v[j] = convert(v[j]);
        }

        char ans;
        fin >> ans;
        bool match[22];
        for (int i = 0; i < 22; i++) {
            match[i] = 0;
        }

        for (int j = 0; j < n; j++) {
            string b;
            fin >> b;
            if (b == v[j]) {
                match[j] = 1;
            }
        }

        vector<int> fails;
        for (int j = 0; j < n; j++) {
            if (match[j] == 0) {
                fails.push_back(j+1);
            }
        }

        if (fails.size() == 0) {
            cout << "MATCH" << endl;
        } else {
            cout << "FAIL: ";
            for (int j = 0; j < fails.size() - 1; j++) {
                cout << fails[j] << ",";
            }

            cout << fails[fails.size() - 1] << endl;
        }
        char ast;
        fin >> ast;
    }

    return 0;
}
