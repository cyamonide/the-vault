#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open ("shuffle.out");
    ifstream fin;
    fin.open("shuffle.in");

    int n;
    fin >> n; // number of cows

    int shuffle[n];

    int itemp;

    for (int i = 0; i < n; i++) {
        fin >> itemp;
        shuffle[i] = itemp-1;
    }

    int a1[n];
    int a2[n];

    for (int i = 0; i < n; i++) {
        fin >> itemp;
        a1[i] = itemp;
    }
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < n; j++) {
            int b = shuffle[j];
            a2[j] = a1[b];
        }
        for (int j = 0; j < n; j++) {
            a1[j] = a2[j];
        }
    }

    for (int j = 0; j < n; j++) {
        fout << a1[j] << "\n";
        cout << a1[j] << "\n";
    }

    // cow in section 3 goes to section 1

    fout.close();

    return 0;
}