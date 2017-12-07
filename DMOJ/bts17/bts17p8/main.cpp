#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    string input;
    cin >> input;

    unsigned long long sum = 0;
    string ssum = "0";

    for (char c : input) {
        if (c == '-') {
            ssum = ssum.substr(0, ssum.size() - 1);
            sum += stoll(ssum);
        } else {
            ssum += c;
            sum += stoll(ssum);
        }
    }

    cout << sum << endl;

    return 0;
}