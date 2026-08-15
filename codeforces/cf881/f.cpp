//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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

const int N = 2e5+5, M = 20, K = 18;

int n, tot, w[N], dep[N], par[N][M];
char s[5];

struct Info {
    int mxpre, mxsuf, mnpre, mnsuf, mx, mn, sum;
    Info() {
        mxpre = mxsuf = mnpre = mnsuf = mx = mn = sum = 0;
    }
}f[N][M];

Info operator+(Info a, Info b) {
    Info c;
    c.mxpre = max(a.mxpre, a.sum + b.mxpre);
    c.mnpre = min(a.mnpre, a.sum + b.mnpre);
    c.mxsuf = max(b.mxsuf, b.sum + a.mxsuf);
    c.mnsuf = min(b.mnsuf, b.sum + a.mnsuf);
    c.mx = max(max(a.mx, b.mx), a.mxsuf + b.mxpre);
    c.mn = min(min(a.mn, b.mn), a.mnsuf + b.mnpre);
    c.sum = a.sum + b.sum;
    return c;
}

Info rev(Info a) {
    swap(a.mxpre, a.mxsuf);
    swap(a.mnpre, a.mnsuf);
    return a;
}

void init(int x, int fa, int v) {
    dep[x] = dep[fa] + 1;
    par[x][0] = fa;
    w[x] = v;
    f[x][0] = Info();
    if (v == 1) f[x][0].mx = f[x][0].mxpre = f[x][0].mxsuf = f[x][0].sum = 1;
    else f[x][0].mn = f[x][0].mnpre = f[x][0].mnsuf = f[x][0].sum = -1;
    rep(j, 1, K) {
        int anc = par[x][j - 1];
        par[x][j] = par[anc][j - 1];
        f[x][j] = f[x][j - 1] + f[anc][j - 1];
    }
}

Info query(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    Info l, r;
    int d = dep[u] - dep[v];
    for (int i = K; i >= 0; --i) {
        if (d >> i & 1) {
            l = l + f[u][i];
            u = par[u][i];
        }
    }
    if (u == v) return l + f[u][0];
    for (int i = K; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            l = l + f[u][i];
            r = r + f[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    return l + f[u][1] + f[v][0] + rev(r);
}

void solve() {
    sci(n);
    
    tot = 1;
    init(tot, 0, 1);
    
    rep(i, 1, n) {
        scanf("%s", s);
        
        if (s[0] == '+') {
            int fa, v;
            sci(fa), sci(v);
            tot++;
            init(tot, fa, v);
        } else {
            int u, v, k;
            sci(u), sci(v), sci(k);
            Info x = query(u, v);
            bool ok = x.mn <= k && k <= x.mx;
            puts(ok ? "Yes" : "No");
        }
    }
}

int main() {
    int t;
    sci(t);
    while (t--) {
        solve();
    }
    return 0;
}