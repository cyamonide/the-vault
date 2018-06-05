// $ g++ -std=c++11 -02 -Wall test.cpp -o test

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

unsigned long long fib(int n) {
    return (pow(1+sqrt(5), n) - pow(1-sqrt(5), n))/(pow(2, n)*sqrt(5));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	printf("%z\n", fib(50));

	cout << fib(50) << endl;

/*
	long long a = 1;
	long long b = 1;
	long long c = 0;

	int n = 50;

	for (int i = 3; i <= n; i++) {
		c = a+b;
		a = b;
		b = c;
	}

	printf("%d\n", c);

	long double e = (pow(1+sqrt(5), n) - pow(1-sqrt(5), n))/(pow(2, n)*sqrt(5));

	printf("%.10f\n", e);
*/

	return 0;
}