// B - Tidy Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

bool isTidy(string n) {
	if (stoull(n) < 10) return true;

	for (int i = 0; i < n.size() - 1; i++) {
		if (n[i] > n[i + 1]) {
			return false;
		}
	}
	return true;
}

string constructTidy(string n) {
	if (n == "1") return "";
	else if (isTidy(n)) return n;
	else {
		return constructTidy(to_string(stoull(n.substr(0, n.size() - 1)) - 1)) + "9";
	}
}

string padNines(string n, int size) {
	if (n.length() != size) {
		for (int i = n.length(); i < size; i++) {
			n = n + "9";
		}
	}

	return n;
}

string stripLeading(string n) {
	if (n[0] == '0') return n.substr(1, n.length() - 1);
	return n;
}

// TODO: comparison function for strings

int main()
{
	ifstream fin;
	fin.open("B-large-practice.in");
	ofstream fout;
	fout.open("output.txt");

	//auto *f = fopen("output.txt", "w");

	int T;
	fin >> T;

	for (int t = 1; t <= T; t++) {
		string n;
		fin >> n;

		if (n == "1") {
			cout << "Case #" << t << ": 1" << endl;
			fout << "Case #" << t << ": 1" << endl;
			continue;
		}

		n = stripLeading(constructTidy(n));

		cout << "Case #" << t << ": " << n << endl;
		fout << "Case #" << t << ": " << n << endl;
	}

    return 0;
}

