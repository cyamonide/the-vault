#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

struct rest {
    int rating;
    int id;

    bool operator<(const rest& rhs) const
    {
        return rating < rhs.rating;
    }
};

int main()
{
    ifstream fin;
    fin.open("DATA31.txt");

    int N, M, K;
    int R;

    for (int i = 0; i < 10; i++) {
        fin >> N >> M >> K;

        priority_queue<rest> p;

        for (int j = 0; j < N; j++) {
            fin >> R;

            rest Rest;
            Rest.rating = R;
            Rest.id = j;

            p.push(Rest);
        }

        /*
        for (int j = 0; j < N; j++) {
            rest u = p.top();
            p.pop();
            cout << u.id << " " << u.rating << endl;
        }
        */

        for (int j = 0; j < K-1; j++) {
            rest a = p.top();
            a.rating -= M;
            p.pop();
            p.push(a);
        }

        cout << p.top().id + 1 << endl;
    }

    return 0;
}
