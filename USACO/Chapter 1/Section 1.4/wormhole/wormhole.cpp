// Created:	Novmember 14, 2017
// Author:	Simon Liu
// Problem:	Wormhole
// Section:	1.4
// Completed:

#include <iostream>
#include <vector>
#include <map>
#define K 4

using namespace std;
int N; // number of cows
vector<int> adjRep; // paired representation
int adj[12]; // adjacency list 
int paired[12];

vector<pair<int, int> > coords;

void generatePartners() {
	for (int i = 0; i < N; i++) {
		if (!paired[i]) {
			adjRep.push_back(i); // append i to this list
			paired[i] = 1;
			generatePartners(); // find next node to insert 
		}
	}

	if (adjRep.size() == N) {
		// DEBUG
		for (int a : adj) cout << a << " ";
		cout << endl;

		checkCycles();
	}

	// remove last element from adjacency list
	try {
		paired[adjRep.back()] = 0;
		adjRep.pop_back();
	} catch (exception e) {
		return;
	}

	return;
}

void checkCycles() {
	// create adjacency list
	for (int i = 0; i < N; i+=2) {
		adj[i] = adjRep[i+1];
		adj[i+1] = adjRep[i];
	}

	// 
	for (int i = 0; i < N; i++) {

	}
}



void nextRight(int a) {

}

// fulfils coords
void takeInput() {
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coords.push_back(make_pair(x, y));
	}
}

int main() {
	cin >> N;

	// identify dead wormholes
	

	generatePartners();

	return 0;
}
