//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

const int MOD = 998244353;
const int G = 3;

int mod_pow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return int(res);
}

void ntt(vector<int>& a, bool invert) {
    int n = int(a.size());

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = mod_pow(G, (MOD - 1) / len);
        if (invert) wlen = mod_pow(wlen, MOD - 2);

        for (int i = 0; i < n; i += len) {
            long long w = 1;
            int half = len >> 1;
            for (int j = 0; j < half; j++) {
                int u = a[i + j];
                int v = int(w * a[i + j + half] % MOD);

                int x = u + v;
                if (x >= MOD) x -= MOD;

                int y = u - v;
                if (y < 0) y += MOD;

                a[i + j] = x;
                a[i + j + half] = y;

                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        int inv_n = mod_pow(n, MOD - 2);
        for (int& x : a) {
            x = int(1LL * x * inv_n % MOD);
        }
    }
}

vector<int> convolution(vector<int> a, vector<int> b) {
    int need = int(a.size()) + int(b.size()) - 1;
    int n = 1;
    while (n < need) n <<= 1;

    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);

    for (int i = 0; i < n; i++) {
        a[i] = int(1LL * a[i] * b[i] % MOD);
    }

    ntt(a, true);
    a.resize(need);
    return a;
}

vector<int> build_phi(int n) {
    vector<int> phi(n + 1), primes;
    vector<int> is_composite(n + 1);

    if (n >= 1) phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }

        for (int p : primes) {
            if (1LL * i * p > n) break;

            is_composite[i * p] = 1;

            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }

    return phi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> query(T);
    int n = 0;

    for (int i = 0; i < T; i++) {
        cin >> query[i];
        n = max(n, query[i]);
    }

    vector<int> phi = build_phi(n);

    vector<int> fac(n + 1), ifac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = int(1LL * fac[i - 1] * i % MOD);
    }

    ifac[n] = mod_pow(fac[n], MOD - 2);
    for (int i = n; i >= 1; i--) {
        ifac[i - 1] = int(1LL * ifac[i] * i % MOD);
    }

    // H[k] = sum_{i=1}^k gcd(i, k)
    vector<int> H(n + 1);
    for (int d = 1; d <= n; d++) {
        for (int m = 1, k = d; k <= n; m++, k += d) {
            int add = int(1LL * d * phi[m] % MOD);
            H[k] += add;
            if (H[k] >= MOD) H[k] -= MOD;
        }
    }

    vector<int> F(n + 1);

    // 小长度直接暴力，避免大量小 NTT 的常数。
    const int LIMIT = 512;

    for (int d = 1; d <= n; d++) {
        int m = n / d;
        int ph = phi[d];

        if (m <= LIMIT) {
            for (int x = 1; x <= m; x++) {
                int j = d * x;
                int coef = 0;

                for (int t = 1; t <= x; t++) {
                    int k = d * t;
                    int term = int(1LL * H[k] * ifac[k] % MOD * ifac[j - k] % MOD);
                    coef += term;
                    if (coef >= MOD) coef -= MOD;
                }

                int add = int(1LL * ph * fac[j] % MOD * coef % MOD);
                F[j] += add;
                if (F[j] >= MOD) F[j] -= MOD;
            }
        } else {
            vector<int> A(m + 1), B(m + 1);

            A[0] = 0;
            for (int t = 1; t <= m; t++) {
                int idx = d * t;
                A[t] = int(1LL * H[idx] * ifac[idx] % MOD);
            }

            for (int t = 0; t <= m; t++) {
                B[t] = ifac[d * t];
            }

            vector<int> C = convolution(std::move(A), std::move(B));

            for (int x = 1; x <= m; x++) {
                int j = d * x;
                int add = int(1LL * ph * fac[j] % MOD * C[x] % MOD);
                F[j] += add;
                if (F[j] >= MOD) F[j] -= MOD;
            }
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + F[i];
        if (ans[i] >= MOD) ans[i] -= MOD;
    }

    for (int x : query) {
        cout << ans[x] << '\n';
    }

    return 0;
}