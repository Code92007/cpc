#include <iostream>
using namespace std;

// 7*11*71*26557*169667*748849 = 2^64 + 61.
// The target's signed long long product overflows and commonly becomes 61.
// Correct answer: 1. No parameters or randomness.
int main() {
    cout << "1\n7\n7 11 71 26557 169667 748849 61\n";
}
