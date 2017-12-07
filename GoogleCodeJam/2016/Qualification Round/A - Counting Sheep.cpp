#include<iostream>
#include<string>
#include<set>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream fin;
  ofstream fout;

  fin.open("A-large-practice.in");
  fout.open("A-large-practice.out");

  set<char> seen;
  int N;
  fin >> N;

  int i;

  for (int q = 1; q <= N; q++) {
    fout << "Case #" << q << ": ";
    fin >> i;
    if (i == 0) {
      fout << "INSOMNIA" << endl;
      continue;
    }
    for (int j = 1; j > 0; j++) {
      for (char a : to_string(i*j)) {
        seen.insert(a);
      }
      if (seen.size() == 10) {
        fout << i*j << endl;
        break;
      }
    }
    seen.clear();
  }

  return 0;
}
