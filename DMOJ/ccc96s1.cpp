// ccc96s1
// Deficient, Perfect, and Abundant
// 5 pts
// (c) Cyamonide 2017.

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int sumDivs = 1;
    int thisNum;
    cin >> thisNum;
    for (int j = 2; j <= sqrt(thisNum); j++) {
      if (j == sqrt(thisNum)) {
        sumDivs += j;
      } else if (thisNum % j == 0) {
        sumDivs += j;
        sumDivs += thisNum/j;
      }
    }
    if (sumDivs == thisNum) {
      cout << thisNum << " is a perfect number." << endl;
    } else if (sumDivs > thisNum) {
      cout << thisNum << " is an abundant number." << endl;
    } else {
      cout << thisNum << " is a deficient number." << endl;
    }
  }

  return 0;
}
