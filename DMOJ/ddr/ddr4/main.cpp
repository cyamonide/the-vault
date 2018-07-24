// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(true) {
        int *foo = (int*)malloc(100000000);
        cout << *foo << endl;
    }

    return 0;
}
