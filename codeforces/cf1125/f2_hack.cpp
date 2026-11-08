#include <bitset>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

// CF 2275F: seed-independent attack on raw mt19937_64 XOR hashing.
// Berlekamp-Massey construction from Sugar_fan's CF blog /entry/153335.
// Upload as GNU G++17, with no parameters. Correct answer: 2.
constexpr int DEG = 19937;
bitset<DEG + 1> relation() {
    mt19937_64 rng;
    bitset<DEG + 1> a, b, c;
    b[DEG] = c[DEG] = 1;
    int len = 0, shift = 1;
    for (int n = 0; n < 2 * DEG; ++n) {
        a >>= 1;
        a[DEG] = rng() & 1;
        if ((c & a).count() % 2 == 0) {
            ++shift;
            continue;
        }
        auto old = c;
        c ^= b >> shift;
        if (2 * len <= n) {
            len = n + 1 - len;
            b = old;
            shift = 1;
        } else {
            ++shift;
        }
    }
    return c;
}

int main() {
    auto selected = relation();
    // Check the indexing and the full 64-bit relation, not just its low bit.
    for (uint64_t seed : {0ULL, 1ULL, 5489ULL, 1791395946ULL,
                          18446744073709551615ULL}) {
        mt19937_64 rng(seed);
        uint64_t total = 0;
        for (int i = 0; i <= DEG; ++i) {
            auto h = rng();
            if (selected[i]) total ^= h;
        }
        if (total != 0) return 1;
    }
    vector<int> primes;
    vector<bool> composite(1000001);
    for (int i = 2; i <= 1000000; ++i) {
        if (!composite[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * i * p > 1000000) break;
            composite[i * p] = true;
            if (i % p == 0) break;
        }
    }
    vector<int> a{1};
    for (int i = 0; i <= DEG; ++i)
        if (selected[i]) a.push_back(primes[i]);
    if (a.size() < 3 || a.size() > 200000) return 1;
    cout << 1 << '\n' << a.size() << '\n';
    for (size_t i = 0; i < a.size(); ++i)
        cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
}
