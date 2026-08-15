#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)

const int N = 2e6+5, mod = 998244353, Primitive_root = 3, LIM = 512;

struct Z {
    int x;
    Z(const int _x = 0) : x(_x) {}
    Z operator + (const Z &r) const { return x + r.x < mod ? x + r.x : x + r.x - mod; }
    Z operator - (const Z &r) const { return x < r.x ? x - r.x + mod : x - r.x; }
    Z operator - () const { return x ? mod - x : 0; }
    Z operator * (const Z &r) const { return static_cast<ll>(x) * r.x % mod; }
    Z operator += (const Z &r) { return x = x + r.x < mod ? x + r.x : x + r.x - mod, *this; }
    Z operator -= (const Z &r) { return x = x < r.x ? x - r.x + mod : x - r.x, *this; }
    Z operator *= (const Z &r) { return x = static_cast<ll>(x) * r.x % mod, *this; }
    friend Z Pow(Z, int);
};

Z Pow(Z x, int y = mod - 2) {
    Z ans = 1;
    for (; y; y >>= 1, x = x * x) if (y & 1) ans = ans * x;
    return ans;
}

namespace Poly {
    Z w[N << 1];
    ull F[N];
    
    void Init() {
        for (int i = 1; i < N; i <<= 1) {
            w[i] = 1;
            Z t = Pow((Z)Primitive_root, (mod - 1) / i / 2);
            for (int j = 1; j < i; ++j) w[i + j] = w[i + j - 1] * t;
        }
    }
    
    int Mod(int x) { return x < mod ? x : x - mod; }
    
    void DFT(vector<Z> &f, int n) {
        if (SZ(f) != n) f.resize(n);
        for (int i = 0, j = 0; i < n; ++i) {
            F[i] = f[j].x;
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        if (n <= 4) {
            for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; j += i << 1) {
                Z *W = w + i;
                ull *F0 = F + j, *F1 = F + j + i;
                for (int k = j; k < j + i; ++k, ++W, ++F0, ++F1) {
                    ull t = (*F1) * (W->x) % mod;
                    (*F1) = *F0 + mod - t, (*F0) += t;
                }
            }
        } else {
            for (int j = 0; j < n; j += 2) {
                int t = F[j + 1];
                F[j + 1] = Mod(F[j] + mod - t), F[j] = Mod(F[j] + t);
            }
            for (int j = 0; j < n; j += 4) {
                int t0 = F[j + 2], t1 = F[j + 3] * w[3].x % mod;
                F[j + 2] = Mod(F[j] + mod - t0), F[j] = Mod(F[j] + t0);
                F[j + 3] = Mod(F[j + 1] + mod - t1), F[j + 1] = Mod(F[j + 1] + t1);
            }
            for (int i = 4; i < n; i <<= 1) for (int j = 0; j < n; j += i << 1) {
                Z *W = w + i;
                ull *F0 = F + j, *F1 = F + j + i;
                for (int k = j; k < j + i; k += 4, W += 4, F0 += 4, F1 += 4) {
                    int t0 = (W->x) * (*F1) % mod;
                    int t1 = (W + 1)->x * (*(F1 + 1)) % mod;
                    int t2 = (W + 2)->x * (*(F1 + 2)) % mod;
                    int t3 = (W + 3)->x * (*(F1 + 3)) % mod;
                    *F1 = Mod(*F0 + mod - t0), *F0 = Mod(*F0 + t0);
                    *(F1 + 1) = Mod(*(F0 + 1) + mod - t1), *(F0 + 1) = Mod(*(F0 + 1) + t1);
                    *(F1 + 2) = Mod(*(F0 + 2) + mod - t2), *(F0 + 2) = Mod(*(F0 + 2) + t2);
                    *(F1 + 3) = Mod(*(F0 + 3) + mod - t3), *(F0 + 3) = Mod(*(F0 + 3) + t3);
                }
            }
        }
        for (int i = 0; i < n; ++i) f[i] = (int)(F[i] % mod);
    }
    
    void IDFT(vector<Z> &f, int n) {
        f.resize(n);
        reverse(f.begin() + 1, f.end());
        DFT(f, n);
        Z I = 1;
        for (int i = 1; i < n; i <<= 1) I *= (mod + 1) / 2;
        for (int i = 0; i < n; ++i) f[i] *= I;
    }
    
    vector<Z> operator * (const vector<Z> &f, const vector<Z> &g) {
        static vector<Z> F, G;
        F = f, G = g;
        int p = 1;
        while (p < SZ(f) + SZ(g) - 1) p <<= 1;
        DFT(F, p);
        DFT(G, p);
        for (int i = 0; i < p; ++i) F[i] *= G[i];
        IDFT(F, p);
        F.resize(SZ(f) + SZ(g) - 1);
        return F;
    }
}

using namespace Poly;

int T, n, H[N], G[N], ans[N], q[N];
int fac[N], ifac[N], inv[N];
int phi[N], prime[N], cnt;
bool ok[N];

void sieve(int n) {
    phi[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        if (!ok[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt; ++j) {
            if (i * prime[j] > n) break;
            ok[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

void init(int n) {
    inv[1] = 1;
    rep(i, 2, n) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    fac[0] = ifac[0] = 1;
    rep(i, 1, n) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
    }
}

void add(int &x,int y) {
    x=(x+y)%mod;
}

int main() {
    Init();
    
    sci(T);
    
    rep(i, 1, T) {
        sci(q[i]);
        n = max(n, q[i]);
    }

    sieve(n);
    init(n);

    // H[k] = sum_{i=1}^k gcd(i, k)
    rep(d, 1, n) {
        for (int m = 1, k = d; k <= n; ++m, k += d) {
            int w = 1ll * d * phi[m] % mod;
            add(H[k], w);
        }
    }

    rep(d, 1, n) {
        int m = n / d;
        int ph = phi[d];

        // if (m <= LIM) {
        //     rep(x, 1, m) {
        //         int j = d * x;
        //         int coef = 0;

        //         rep(t, 1, x) {
        //             int k = d * t;
        //             int term = 1ll * H[k] * ifac[k] % mod * ifac[j - k] % mod;
        //             add(coef, term);
        //         }

        //         int w = 1ll * ph * fac[j] % mod * coef % mod;
        //         add(G[j], w);
        //     }
        // } else {
            vector<Z> A(m + 1), B(m + 1);
            A[0] = 0;
            rep(t, 1, m) {
                int idx = d * t;
                A[t] = 1ll * H[idx] * ifac[idx] % mod;
            }

            rep(t, 0, m) {
                B[t] = ifac[d * t];
            }

            vector<Z> C = A * B;

            rep(x, 1, m) {
                int j = d * x;
                int w = 1ll * ph * fac[j] % mod * C[x].x % mod;
                add(G[j], w);
            }
        // }
    }
    
    rep(i, 1, n) {
        ans[i] = (ans[i - 1] + G[i])%mod;
    }

    rep(i, 1, T) {
        int x=q[i];
        pte(ans[x]);
    }

    return 0;
}