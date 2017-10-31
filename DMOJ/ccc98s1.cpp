// ccc98s1
// Censor
// 5 pts
// (c) Cyamonide 2017.

#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  cin.ignore();

  for (int i = 0; i < n; i++) {
    string input = "";
    string thisWord = "";

    getline(cin, input);

    int thisLen = 0;

    for (char a : input) {
      if (a != ' ') {
        thisLen++;
        thisWord = thisWord + a;
      } else {
        if (thisLen == 4) {
          cout << "**** ";
        } else {
          cout << thisWord << " ";
        }
        thisWord = "";
        thisLen = 0;
      }
    }
    if (thisLen == 4) {
      cout << "**** ";
    } else {
      cout << thisWord << " ";
    }
    cout << endl;

  }

  return 0;
}
