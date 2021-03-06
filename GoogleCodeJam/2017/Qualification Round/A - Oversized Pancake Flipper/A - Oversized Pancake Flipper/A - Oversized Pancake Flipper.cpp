// A - Oversized Pancake Flipper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

#define happy true
#define blank false

deque<bool> flip(deque<bool> v, int start, int k) {
	for (int i = start; i < start + k; i++) {
		v[i] = !v[i];
	}

	return v;
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	auto *f = fopen("output.txt", "w");

	int T; // test cases
	fin >> T;

	string S; // string
	int K; // flipper size

	for (int q = 1; q <= T; q++) {
		fin >> S >> K;

		deque<bool> surface;
		for (char a : S) {
			if (a == '+') {
				surface.push_back(happy);
			}
			else {
				surface.push_back(blank);
			}
		}

		int index = 0;
		int count = 0;
		while (index <= S.length() - K) {
			if (surface[index] != happy) {
				surface = flip(surface, index, K);
				count++;
			}
			index++;
		}

		bool isPossible = true;
		for (int i = S.length() - K; i < S.length(); i++) {
			if (surface[i] == blank) {
				isPossible = false;
				break;
			}
		}

		if (!isPossible) {
			printf("Case #%i: IMPOSSIBLE\n", q);
			fprintf(f, "Case #%i: IMPOSSIBLE\n", q);
		}
		else {
			printf("Case #%i: %i\n", q, count);
			fprintf(f, "Case #%i: %i\n", q, count);
		}
	}

    return 0;
}
//
//// A - Oversized Pancake Flipper.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//#define happy true
//#define blank false
//
//deque<bool> flip(deque<bool> v, int start, int k) {
//	for (int i = start; i < start + k; i++) {
//		v[i] = !v[i];
//	}
//
//	return v;
//}
//
//int main()
//{
//	ifstream fin;
//	fin.open("input.txt");
//
//	int T; // test cases
//	fin >> T;
//
//	string S; // string
//	int K; // flipper size
//
//	for (int q = 1; q <= T; q++) {
//		fin >> S >> K;
//
//		deque<bool> surface;
//		deque<bool> surface2;
//		for (char a : S) {
//			if (a == '+') {
//				surface.push_back(happy);
//				surface2.push_front(happy);
//			}
//			else {
//				surface.push_back(blank);
//				surface2.push_front(blank);
//			}
//		}
//
//		int index = 0;
//		int count = 0;
//		int count2 = 0;
//		while (index <= S.length() - K) {
//			if (surface[index] != happy) {
//				surface = flip(surface, index, K);
//				count++;
//			}
//			if (surface2[index] != happy) {
//				surface2 = flip(surface2, index, K);
//				count2++;
//			}
//			index++;
//		}
//
//		bool isPossible = true;
//		for (int i = S.length() - K; i < S.length(); i++) {
//			if (surface[i] == blank) {
//				isPossible = false;
//				break;
//			}
//		}
//
//		bool isPossible2 = true;
//		for (int i = S.length() - K; i < S.length(); i++) {
//			if (surface2[i] == blank) {
//				isPossible2 = false;
//				break;
//			}
//		}
//
//		if (isPossible == isPossible2 && isPossible == false) {
//			printf("Case #%i: IMPOSSIBLE\n", q);
//		}
//		else if (isPossible && isPossible2) {
//			printf("Case #%i: %i\n", q, min(count, count2));
//		}
//		else if (isPossible) {
//			printf("Case #%i: %i\n", q, count);
//		}
//		else {
//			printf("Case #%i: %i\n", q, count2);
//		}
//	}
//
//	return 0;
//}
//


