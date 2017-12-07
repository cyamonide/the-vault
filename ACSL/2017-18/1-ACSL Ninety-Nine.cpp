#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// returns score after putting down a card
int putDown(int score1, int median) {
    // final score
    int score2 = score1;
    // calculate new score based on median card
    switch(median) {
        case 9:
            break;
        case 10:
            score2 -= 10;
            break;
        case 7:
            if (score1 < 93) score2 += 7;
            else return score2 += 1;
            break;
        default:
            score2 += median;
            break;
    }
    // check for changes in score boundary
    bool isCrossed = false;
    isCrossed |= (score1 >= 34 && score2 <= 33);
    isCrossed |= (score1 <= 33 && score2 >= 34);
    isCrossed |= (score1 >= 56 && score2 <= 55);
    isCrossed |= (score1 <= 55 && score2 >= 56);
    isCrossed |= (score1 >= 78 && score2 <= 77);
    isCrossed |= (score1 <= 77 && score2 >= 78);
    if (isCrossed) score2 += 5;

    return score2;
}


int main() {
    vector<string> output;

    map<char, int> card;
    card['2'] = 2;
    card['3'] = 3;
    card['4'] = 4;
    card['5'] = 5;
    card['6'] = 6;
    card['7'] = 7;
    card['8'] = 8;
    card['9'] = 9;
    card['T'] = 10;
    card['J'] = 11;
    card['Q'] = 12;
    card['K'] = 13;
    card['A'] = 14;

    // initial hands of first and second players
    vector<int> initHand1;
    vector<int> initHand2;

    // take input for initial first and second hands
    for (int i = 1; i <= 5; i++) {
        string stemp;
        cin >> stemp;
        initHand1.push_back(card[stemp[0]]);
    }
    for (int i = 1; i <= 5; i++) {
        string stemp;
        cin >> stemp;
        initHand2.push_back(card[stemp[0]]);
    }

    // sort initial hands
    sort(initHand1.begin(), initHand1.end());
    sort(initHand2.begin(), initHand2.end());

    /* cumulative score */
    int score;

    // main loop, with lines 2 to 6 of input
    for (int line = 2; line <= 6; line++) {
        // copy hand 1 and hand 2
        vector<int> hand1 = initHand1;
        vector<int> hand2 = initHand2;
        // cumulative score
        int score;
        // read initial score
        string stemp;
        cin >> stemp;
        stemp = stemp.substr(0, stemp.size()-1);
        score = stoi(stemp);
        // winning player
        int win = 0;
        // final score
        int finalScore = 0;

        // 10 cards players 1 and 2 pick up
        for (int pickup = 1; pickup <= 10; pickup+=2) {
            // calculate median card
            vector<int>::const_iterator med = hand1.begin();
            advance(med, 2);
            // place median card
            score = putDown(score, *med);
            // replace median card from vector with new card
            string stemp;
            cin >> stemp;
            hand1[2] = card[stemp[0]];
            // sort
            sort(hand1.begin(), hand1.end());
            // check for game finish
            if (score > 99 && win == 0) {
                win = 2;
                finalScore = score;
            }

            // calculate median card
            med = hand2.begin();
            advance(med, 2);
            // place median card
            score = putDown(score, *med);
            // replace median card from vector with new card
            cin >> stemp;
            hand2[2] = card[stemp[0]];
            // sort
            sort(hand2.begin(), hand2.end());
            // check for game finish
            if (score > 99 && win == 0) {
                win = 1;
                finalScore = score;
            }
        }

        // final card place-down if necessary
        if (score <= 99) {
            // calculate median card
            vector<int>::const_iterator med = hand1.begin();
            advance(med, 2);
            // place median card
            score = putDown(score, *med);
            if (score > 99 && win == 0) {
                win = 2;
                finalScore = score;
            }
            // calculate median card
            med = hand2.begin();
            advance(med, 2);
            // place median card
            score = putDown(score, *med);
            if (score > 99 && win == 0) {
                win = 1;
                finalScore = score;
            }
        }

        // output
        output.push_back(to_string(finalScore) + ", Player #" + to_string(win));
        // cout << finalScore << ", Player #" << win << endl;
    }

    for (string a : output) {
        cout << a << endl;
    }

    return 0;
}
