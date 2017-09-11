#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // length of wet mud
    int M; // number of wet parts that will become dry
    int J; // how far denesh can jump

    cin >> N >> M >> J;

    // path of -1 times
    vector<int> path;
    for (int i = 0; i < N; i++) {
        path.push_back(-1);
    }

    // get drying times
    for (int i = 1; i <= M; i++) {
        int p;
        int t;
        cin >> p >> t;
        path[p-1] = t;
    }

    // now a path of N units has been created, with the pth value being the drying time of the pth inch of mud.
    // a value of -1 indicates an inch of mud that will not dry

    vector<int>::const_iterator denesh = path.begin()-1; // the current position of denesh
    int t = 0; // the current time
    // keep on checking for the next jump until denesh reaches the end

    while (denesh <= path.end() - J) {
        // let us define FOV as the next J inches of mud
        // extract subvector of denesh's current FOV
        vector<int>::const_iterator first = denesh + 1;
        vector<int>::const_iterator last = first + J;
        vector<int> FOV(first, last);

        // check if a possible jump exists in this FOV
        bool isPossible = false;
        for (int a : FOV) {
            if (a != -1) {
                isPossible = true;
                break;
            }
        }
        if (!isPossible) {
            cout << -1 << endl;
            return 0;
        }

        // find the minimum value in this FOV
        int min;
        for (int a : FOV) {
            if (a != -1) min = a;
            break;
        }
        for (int a : FOV) {
            if (a < min && a != -1) min = a;
        }
        if (min > t) {
            t = min;
        }

        cout << min << endl;

        // traverse backward and let denesh jump to this value
        while (last >= first) {
            if (*last == min) {
                denesh = last;
                break;
            } else {
                last--;
            }
        }
    }

    cout << t << endl;

    return 0;
}