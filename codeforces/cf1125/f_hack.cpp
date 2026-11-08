#include <iostream>
#include <vector>
#include <random>
#include <cstdint>
#include <cstdlib>
using namespace std;
using ull = uint64_t;

// CF 2275F, Round 1125: generator targeting time(nullptr) seeds.
// Deterministic default window; regenerate the constant for a later hack.
// Optional first argument: explicit starting Unix second.
// Every test has correct answer 2. A matching target seed causes WA.
int main(int argc, char** argv) {
    ull start = argc > 1 ? strtoull(argv[1], nullptr, 10)
                         : 1791395946ULL;
    vector<int> prime;
    for (int x = 2; prime.size() < 61; ++x) {
        bool ok = true;
        for (int p : prime) {
            if (p * p > x) break;
            if (x % p == 0) { ok = false; break; }
        }
        if (ok) prime.push_back(x);
    }
    cout << 3200 << '\n';
    for (ull seed = start; seed < start + 3200; ++seed) {
        mt19937_64 rng(seed);
        ull basis[60]{}, masks[60]{}, chosen = 0;
        for (int i = 0; i < 61; ++i) {
            ull x = rng() % 1000000000000000000ULL;
            ull mask = 1ULL << i;
            for (int b = 59; b >= 0; --b) {
                if (!((x >> b) & 1)) continue;
                if (!basis[b]) {
                    basis[b] = x;
                    masks[b] = mask;
                    break;
                }
                x ^= basis[b];
                mask ^= masks[b];
            }
            if (x == 0) { chosen = mask; break; }
        }
        vector<int> a{1};
        for (int i = 0; i < 61; ++i)
            if ((chosen >> i) & 1) a.push_back(prime[i]);
        cout << a.size() << '\n';
        for (size_t i = 0; i < a.size(); ++i)
            cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
    }
}
