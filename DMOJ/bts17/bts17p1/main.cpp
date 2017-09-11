#include <iostream>
using namespace std;

int main() {
    // input string with no periods
    string in;
    getline(cin, in);

    // traverse through every character in input
    int i = 0;
    while (true) {
        if (i+1 >= in.size()) {
            break;
        }
        char thisC = in[i+1];
        if (isupper(thisC)) {
            cout << '.' << in[i];
        } else {
            cout << in[i];
        }
        i++;
    }

    cout << in[i] << '.' << endl;

    return 0;
}