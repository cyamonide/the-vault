#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

vector<string> field;
vector<vector<int> > minDist;
vector<vector<bool> > v;
int thisLen = -1;

/* enum ID {
    cstart, cemp, cwall, ccam, cL, cR, cU, cD
}; */

char cemp = '.';
char cwall = 'W';
char ccamo = 'C';
char ccam = 'c';
char cL = 'L';
char cU = 'U';
char cR = 'R';
char cD = 'D';

void findPath(pair<int, int> thisNode);

void moveLeft(pair<int, int> thisNode) {
    // try moving left
    findPath(MP(thisNode.F, thisNode.S-1));
}

void moveUp(pair<int, int> thisNode) {
    // try moving up
    findPath(MP(thisNode.F-1, thisNode.S));
}

void moveRight(pair<int, int> thisNode) {
    // try moving right
    findPath(MP(thisNode.F, thisNode.S+1));
}

void moveDown(pair<int, int> thisNode) {
    // try moving down
    findPath(MP(thisNode.F+1, thisNode.S));
}

void findPath(pair<int, int> thisNode) {
    // cout << "checking: " << thisNode.F << " " << thisNode.S << endl;

    int id = field[thisNode.F][thisNode.S];
    
    if (id == cwall || id == ccam || id == ccamo) {
        // do nothing, not a valid move
        return;
        // cout << "wall" << endl;
    }

    // set this node to visited
    thisLen++;

    // exit if value already optimized
    if (minDist[thisNode.F][thisNode.S] >= 0 && thisLen >= minDist[thisNode.F][thisNode.S]) {
        thisLen--;
        v[thisNode.F][thisNode.S] = 0;
        return;
    }

    
    if (id == cL) {
        // exit if already visited
        if (!v[thisNode.F][thisNode.S]) {
            // conveyor belt does not increment step, but it moves the robot in that direction
            // cout << "leftBelt" << endl;
            v[thisNode.F][thisNode.S] = 1;
            thisLen--;
            moveLeft(thisNode);
            thisLen++;
            v[thisNode.F][thisNode.S] = 0;
        }
    } else if (id == cU) {
        // exit if already visited
        if (!v[thisNode.F][thisNode.S]) {
            // cout << "upBelt" << endl;
            v[thisNode.F][thisNode.S] = 1;
            thisLen--;
            moveUp(thisNode);
            thisLen++;
            v[thisNode.F][thisNode.S] = 0;
        }
    } else if (id == cR) {
        // exit if already visited
        if (!v[thisNode.F][thisNode.S]) {
            // cout << "rightBelt" << endl;
            v[thisNode.F][thisNode.S] = 1;
            thisLen--;
            moveRight(thisNode);
            thisLen++;
            v[thisNode.F][thisNode.S] = 0;
        }
    } else if (id == cD) {
        // exit if already visited
        if (!v[thisNode.F][thisNode.S]) {
            // cout << "downBelt" << endl;
            v[thisNode.F][thisNode.S] = 1;
            thisLen--;
            moveDown(thisNode);
            thisLen++;
            v[thisNode.F][thisNode.S] = 0;
        }
    } else { // if it is an empty cell
   
        // update the distance value
        if (minDist[thisNode.F][thisNode.S] == -1 || thisLen < minDist[thisNode.F][thisNode.S]) {
            minDist[thisNode.F][thisNode.S] = thisLen;
        } 
        /* else if (minDist[thisNode.F][thisNode.S] >= 0 && minDist[thisNode.F][thisNode.S] < thisLen) {
            thisLen--;
            v[thisNode.F][thisNode.S] = 0;
            return;
        } */
        
        moveLeft(thisNode);
        moveUp(thisNode);
        moveRight(thisNode);
        moveDown(thisNode);
    }

    // unvisit this node
    thisLen--;

    return;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    string stemp;
    vector<int> vtemp;
    pair<int, int> startNode;
    REP(i, 1, N) {
        cin >> stemp;
        /* vtemp.clear();
        REP(j, 1, M) {
            char a = stemp[j-1];
            switch(a) {
                case 'S':
                    vtemp.PB(cstart);
                    startNode = MP(i-1, j-1);
                    break;
                case '.':
                    vtemp.PB(cemp);
                    break;
                case 'W':
                    vtemp.PB(cwall);
                    break;
                case 'C':
                    vtemp.PB(ccam);
                    break;
                case 'L':
                    vtemp.PB(cL);
                    break;
                case 'R':
                    vtemp.PB(cR);
                    break;
                case 'U':
                    vtemp.PB(cU);
                    break;
                case 'D':
                    vtemp.PB(cD);
                    break;
            }
        }
        field.PB(vtemp);
        */
        field.PB(stemp);
    }

    /*
    for (vector<int> a : field) {
        for (int b : a) {
            cout << b << " ";
        } cout << endl;
    }
    */

    // TODO: CONSTRUCT CAMERA FOV SQUARES


    // construct parallel visited array
    vector<bool> btemp;
    REP(i, 1, M) btemp.PB(0);
    REP(i, 1, N) v.PB(btemp);

    // construct parallel minDist array
    REP(i, 1, N) {
        vtemp.clear();
        REP(j, 1, M) {
            if (field[i-1][j-1] == cemp) {
                vtemp.PB(-1);
            } else {
                vtemp.PB(-2);
            }
            // find startnode
            if (field[i-1][j-1] == 'S') {
                startNode = MP(i-1, j-1);
            }
        }
        minDist.PB(vtemp);
    }

    bool special = false;

    REP(i, 0, N-1) {
        REP(j, 0, M-1) {
            if (field[i][j] == ccamo) {
                // all up left right and down will be converted to ccam
                // left
                int inc = 1;
                while (field[i-inc][j] != 'W') {
                    if (field[i-inc][j] != '.') {
                        if (field[i-inc][j] == 'S') {
                            special = true;
                        }
                        inc++;
                        continue;
                    }
                    field[i-inc][j] = ccam;
                    inc++;
                }
                inc = 1;
                while (field[i+inc][j] != 'W') {
                    if (field[i+inc][j] != '.') {
                        if (field[i+inc][j] == 'S') {
                            special = true;
                        }
                        inc++;
                        continue;
                    }
                    field[i+inc][j] = ccam;
                    inc++;
                }
                inc = 1;
                while (field[i][j-inc] != 'W') {
                    if (field[i][j-inc] != '.') {
                        if (field[i][j-inc] == 'S') {
                            special = true;
                        }
                        inc++;
                        continue;
                    }
                    field[i][j-inc] = ccam;
                    inc++;
                }
                inc = 1;
                while (field[i][j+inc] != 'W') {
                    if (field[i][j+inc] != '.') {
                        if (field[i][j+inc] == 'S') {
                            special = true;
                        }
                        inc++;
                        continue;
                    }
                    field[i][j+inc] = ccam;
                    inc++;
                }
            }
        }
    }

    
    // for (string a : field) {
    //     cout << a << endl;
    // }
    
    if (!special) {
        findPath(startNode);
    }

    // output minDist array
    REP(i, 0, N-1) {
        REP(j, 0, M-1) {
            if (minDist[i][j] != -2) {
                cout << minDist[i][j] << "\n";
            }
        }
    }

    return 0;
}