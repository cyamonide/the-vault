#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector<string> tokenize(string s, char t) {
    string stemp;
    vector<string> toked;
    for (char a : s) {
        if (a != ' ') {
            stemp += a;
        } else {
            toked.push_back(stemp);
            stemp = "";
        }
    }
    toked.push_back(stemp);
    return toked;
}

int main()
{
    ifstream fin;
    fin.open("DATA21.txt");

    for (int query = 0; query < 1; query++) {
        string sinput;
        int w;

        vector<int> foobar = {2, 3, 4};

        fin >> w;
        ws(fin);
        getline(fin, sinput);

        vector<string> spidernob = tokenize(sinput, ' ');

        for (string a : spidernob) {
            cout << a << endl;
        }
    }

    return 0;
}
