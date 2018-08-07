// ECOO Round 1
// (c) Victoria Park CI Team 1, 2017
// Eric Li, Simon Liu, Richard(Linyin) Sun, Andrew Wang
// P2 - Chocolate

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

ifstream fin;

int main() {

    /* File IO */
    fin.open("DATA21.txt");

    for (int testCase = 1; testCase <= 10; testCase++) {
        int numChoc;
        fin >> numChoc;

        int maxScore = 0;
        vector<string> winners;

        // database
        multimap<string, vector<int> > database;
        database.clear();

        // name
        string name;
        fin >> name;

        string stemp;

        for (int chocs = 1; chocs <= numChoc; chocs++) {
            fin >> stemp;

            int thisSum = 0;
            int itemp;


            int P = 0;
            int F = 0;
            int G = 0;

            // judge input
            while (stemp == "J") {
                fin >> itemp;
                P += itemp;
                fin >> itemp;
                F += itemp;
                fin >> itemp;
                G += itemp;
                fin >> stemp;
            }

            thisSum = P + F + G;

            vector<int> metaData;
            metaData.push_back(P);
            metaData.push_back(F);
            metaData.push_back(G);

            // adds to winner vector
            if (thisSum > maxScore) {
                database.clear();
                database.insert(make_pair(name, metaData));
                maxScore = thisSum;
            } else if (thisSum == maxScore) {
                database.insert(make_pair(name, metaData));
            }

            name = stemp;
        } // end of chocs for loop

        int maxG = 0;
        int maxF = 0;
        int maxP = 0;

        // G tiebreaker
        for (pair<string, vector<int> > a : database) {
            if (a.second[2] > maxG) {
                maxG = a.second[2];
            }
        }

        multimap<string, vector<int> > database2;
        database2.clear();

        for (pair<string, vector<int> > a : database) {
            if (a.second[2] == maxG) {
                database2.insert(a);
            }
        }

        database = database2;
        database2.clear();

        // F tiebreaker
        for (pair<string, vector<int> > a : database) {
            if (a.second[1] > maxF) {
                maxF = a.second[1];
            }
        }
        database2.clear();
        for (pair<string, vector<int> > a : database) {
            if (a.second[1] == maxF) {
                database2.insert(a);
            }
        }

        database = database2;
        database2.clear();

        // P tiebreaker
        for (pair<string, vector<int> > a : database) {
            if (a.second[0] > maxP) {
                maxP = a.second[0];
            }
        }
        database2.clear();
        for (pair<string, vector<int> > a : database) {
            if (a.second[0] == maxP) {
                database2.insert(a);
            }
        }

        vector<string> winNames;

        for (pair<string, vector<int> > a : database) {
            winNames.push_back(a.first);
        }

        // output
        for (int i = 0; i < winNames.size() - 1; i++) {
            cout << winNames[i] << ", ";
        }
        cout << winNames[winNames.size() - 1] << endl;

        winNames.clear();
        database.clear();
        database2.clear();
    }

    return 0;
}
