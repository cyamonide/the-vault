#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <fstream>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

struct Foobar {
    int foobat = 0;
};

// playing field
int field[8][8];
// current angle direction
int thisTheta;

deque<int> hex2Oct(string hex) {
    deque<int> output;
    long long dec = 0;
    
    // hex to decimal
    REP(i, 0, 5) {
        char a = hex[5-i];
        if (a >= 48 && a <= 57) {
            dec += (a-48)*pow(16, i);
        } else {
            dec += (a-55)*pow(16, i);
        }
    }

    // decimal to octal
    REP(i, 0, 7) {
        output.push_back(dec/pow(8, 7-i));
        dec -= output.back()*pow(8, 7-i);
    }

    return output;
}

void printField() {
    REP(i, 0, 7) {
        REP(j, 0, 7) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}

pair<int, int> move(pair<int, int> thisLoc) {
    cout << "thisTheta1: " << thisTheta << "\n";
    // add 180 degrees
    thisTheta += 4;
    thisTheta %= 8;
    cout << "thisTheta2: " << thisTheta << "\n";
    // add angle
    thisTheta += field[thisLoc.F][thisLoc.S];
    thisTheta %= 8;

    cout << "thisTheta3: " << thisTheta << "\n";

    int a = thisLoc.F;
    int b = thisLoc.S;

    cout << a << " " << b << "\n";

    // move pointer
    switch(thisTheta) {
        case(0):
            a += 0;
            b += 1;
            break;
        case(1):
            a += 1;
            b += 1;
            break;
        case(2):
            a += 1;
            b += 0;
            break;
        case(3):
            a += 1;
            b += 7;
            break;
        case(4):
            a += 0;
            b += 7;
            break;
        case(5):
            a += 7;
            b += 7;
            break;
        case(6):
            a += 7;
            b += 0;
            break;
        case(7):
            a += 7;
            b += 1;
            break;
    }

    a %= 8;
    b %= 8;

    return MP(a, b);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // file IO
    ifstream fin;
    fin.open("acsl-walk-judge.in");
    ofstream fout;
    fout.open("acsl-walk-judge.out");

    string stemp;
    // take input
    REP(i, 0, 7) {
        fin >> stemp;
        deque<int> arr = hex2Oct(stemp);
        REP(j, 0, 7) {
            field[7-i][j] = arr[j];
        }
    }
    
    printField();

    REP(w, 1, 5) {
        // starting location
        pair<int, int> thisLoc;
        string stemp1, stemp2;
        fin >> stemp1 >> stemp2;
        thisLoc = make_pair(7-stemp1[0]+49, stemp2[0]-49);

        cout << "thisLoc: " << thisLoc.F << " " << thisLoc.S << "\n";

        // current angle
        fin >> stemp;
        switch(stemp[0]) {
            case('R'):
                thisTheta = 4;
                break;
            case('B'):
                thisTheta = 6;
                break;
            case('L'):
                thisTheta = 0;
                break;
            case('A'):
                thisTheta = 2;
                break;
        }

        // max steps
        int maxSteps;
        fin >> stemp;
        maxSteps = stoi(stemp);
        
        // start travelling on path
        REP(q, 1, maxSteps) {
            thisLoc = move(thisLoc);
        }

        cout << "\t\tANSWER: " << 7-thisLoc.F+1 << ", " << thisLoc.S+1 << "\n";

        fout << 7-thisLoc.F+1 << ", " << thisLoc.S+1 << "\n";
    
    }

    fin.close();
    fout.close();

    return 0;
}