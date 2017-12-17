#include <iostream>
#include <fstream>
#include <string>

#include <deque>
#include <vector>

using namespace std;

int main() {
    string PROBLEM_ID = "homework";
    ifstream fin;
    fin.open(PROBLEM_ID + ".in");
    ofstream fout;
    fout.open(PROBLEM_ID + ".out");

    int N;
    fin >> N;
    // input n

    int itemp;
    deque<int> scores;

    for (int i = 1; i <= N; i++) {
        fin >> itemp;
        scores.push_front(itemp);
    } // backwards deque of scores

    vector<unsigned long> cumsum;
    unsigned long ongoingScore = 0;

    // cumulative sum of scores
    for (int i = 0; i < N; i++) {
        ongoingScore += scores[i];
        cumsum.push_back(ongoingScore);
    }

    // ongoing minimum scores
    vector<int> onmin;
    int ongoingMin = scores[0];
    for (int i = 0; i < N; i++) {
        ongoingMin = min(ongoingMin, scores[i]);
        onmin.push_back(ongoingMin);
    }

    // output vector
    deque<int> output;
    double maxScore = (cumsum[N-2] - onmin[N-2])/(N-2);
    cout << maxScore << endl;
    
    // K
    for (double k = N-2; k >= 1; k--) {
        if ( ((cumsum[k] - onmin[k])/k) > maxScore ) {
            maxScore = ((cumsum[k] - onmin[k])/k);

            output.clear();
            output.push_back(N - k - 1);
        } else if ( ((cumsum[k] - onmin[k])/k) == maxScore ) {
            output.push_back(N - k - 1);
        }
        cout << k << " " << ((cumsum[k] - onmin[k])/k) << endl;
    }

    for (int i : output) {
        fout << i << "\n";
    }

    fout.close(); return 0;
}