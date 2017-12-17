#include<iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main() {
    auto t1 = Clock::now();

    for (long long i = 1; i <= 1000000; i++) {
        cout << i << "\n";
    }

    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: (\\n)" 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " nanoseconds" << std::endl;
}