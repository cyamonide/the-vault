// (C) 2016 Cyamonide.
// 2016-11-29
// ccc16j2
// CCC '16 J2 - Magic Squares

#include <iostream>
#include <vector>
using namespace std;

int main() {

vector<int> vtemp;
vector<vector<int> > square;
int itemp;

for (int i = 1; i <= 4; i++) {
	vtemp.clear();
	for (int j = 1; j <= 4; j++) {
		cin >> itemp;
		vtemp.push_back(itemp);
	}
	square.push_back(vtemp);
}

int sum = 0;
for (int i = 0; i <= 3; i++) {
	sum += square[0][i];
}

int thisSum = 0;

for (int i = 0; i <= 3; i++) {
	thisSum = 0;
	for (int j = 0; j <= 3; j++) {
		thisSum += square[i][j];
	}
	if (thisSum != sum) {
		cout << "not magic" << endl;
		return 0;
	}
}

cout << "magic" << endl;
return 0;
}
