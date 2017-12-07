#include <iostream>
#include <vector>
using namespace std;

int main() {
    float numerator = 1.0;
    float denominator = 1.0;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int evil;
        cin >> evil;
        int total;
        cin >> total;
        int good = total - evil;
        numerator *= good;
        denominator *= total;
    }

    cout << numerator/denominator << endl;

    return 0;
}