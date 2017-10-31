// ccc17s3
// Nailed It!
// 7 pts
// (C) Cyamonide 2017.

#include <iostream>
#include <vector>
using namespace std;

int main() {

  // INPUT: N for number of boards, then L_i for each board's length
  // OUPTUT: length of longest fence and number of different heights it could have

  int boards[2001];
  for (int i = 0; i <= 2001; i++) {boards[i] = 0;}

  int N;
  cin >> N;

  int itemp;
  for (int i = 0; i < N; i++) {
    cin >> itemp;
    boards[itemp]++;
  }

  // END of input, boards[i] contains number of i-length boards

  int longestFence[2]; // length, ways
  longestFence[0] = 0; // length
  longestFence[1] = 1; // ways

  for (int height = 4000; height > 0; height--) { // for every height
    int thisLength = 0;
    for (int i = height; i > height/2; i--) {
      if (i <= 2000 && height-i <= 2000) {
        if (boards[i] < boards[height-i]) {
          thisLength += boards[i];
        } else {
          thisLength += boards[height-i];
        }
      }
    }
    // account for exactly height/2.0
    if (height % 2 == 0) {
      thisLength += boards[height/2]/2;
    }
    if(thisLength > longestFence[0]) {
      longestFence[0] = thisLength;
      longestFence[1] = 1;
    } else if (thisLength == longestFence[0]) {
      longestFence[1]++;
    }
  }

  cout << longestFence[0] << " " << longestFence[1] << endl;

  return 0;
}
