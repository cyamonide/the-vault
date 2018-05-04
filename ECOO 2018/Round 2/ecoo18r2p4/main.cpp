#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

using namespace std;

/*
Problem 4
*/

int main() {
    ifstream fin;
    fin.open("DATA40.txt");

    for (int query = 1; query <= 10; query++) {
        double foo = 0.0055404600;
        double michael = 0;

        for (int i = 1; i <= 2000; i++) {
            michael += foo;
        }

        printf("%.15f\n", michael);
    }

    return 0;
}
