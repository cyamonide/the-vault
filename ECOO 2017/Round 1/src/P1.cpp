// ECOO Round 1
// (c) Victoria Park CI Team 1, 2017
// Eric Li, Simon Liu, Richard(Linyin) Sun, Andrew Wang
// P1 - Munch n Brunch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;

int main() {

    /* File IO */
    fin.open("DATA12.txt");

    for (int testCase = 1; testCase <= 10; testCase++) {

        int tripCost;
        fin >> tripCost;

        double p1, p2, p3, p4;
        fin >> p1 >> p2 >> p3 >> p4;

        int totalStudents;
        fin >> totalStudents;

        p1 *= totalStudents;
        p2 *= totalStudents;
        p3 *= totalStudents;
        p4 *= totalStudents;

        p1 *= 12;
        p2 *= 10;
        p3 *= 7;
        p4 *= 5;

        int funds = p1 + p2 + p3 + p4;
        funds /= 2;

        if (funds >= tripCost) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
