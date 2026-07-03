#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
typedef array<ll,3> A;
#define fi first
#define se second
#define pb pushdown_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)

const int N = 2e5 + 5;

int n, q;
int a[N], pre[N], nxt[N], maxR[N];
map<int, int> last;

// 区间加，区间求最大值
struct segtree {
    int n;
    struct node {
        int l, r, mx, lazy;
    } e[N << 2];
    
    #define l(p) e[p].l
    #define r(p) e[p].r
    #define mx(p) e[p].mx
    #define lazy(p) e[p].lazy
    
    void pushdown(int p) {
        if (lazy(p)) {
            mx(p<<1) += lazy(p);
            mx(p<<1|1) += lazy(p);
            lazy(p << 1) += lazy(p);
            lazy(p << 1 | 1) += lazy(p);
            lazy(p) = 0;
        }
    }
    
    void up(int p) {
        mx(p) = max(mx(p << 1), mx(p << 1 | 1));
    }
    
    void bld(int p, int l, int r) {
        l(p) = l; 
        r(p) = r;
        mx(p) = lazy(p) = 0;
        if (l == r) return;
        int mid = l + r >> 1;
        bld(p << 1, l, mid);
        bld(p << 1 | 1, mid + 1, r);
        up(p);
    }
    
    void init(int _n) {
        n = _n;
        bld(1, 1, n);
    }
    
    void range_add(int p, int ql, int qr, int v) {
        if (ql > r(p) || qr < l(p)) return;
        if (ql <= l(p) && r(p) <= qr) {
            mx(p) += v;
            lazy(p) += v;
            return;
        }
        pushdown(p);
        int mid = l(p) + r(p) >> 1;
        if (ql <= mid) range_add(p << 1, ql, qr, v);
        if (qr > mid) range_add(p << 1 | 1, ql, qr, v);
        up(p);
    }
    
    int query_max(int p, int ql, int qr) {
        if (ql > r(p) || qr < l(p)) return 0;
        if (ql <= l(p) && r(p) <= qr) {
            return mx(p);
        }
        pushdown(p);
        int mid = l(p) + r(p) >> 1;
        int res = 0;
        if (ql <= mid) res = max(res, query_max(p << 1, ql, qr));
        if (qr > mid) res = max(res, query_max(p << 1 | 1, ql, qr));
        return res;
    }
    
    void add(int l, int r, int v) {
        if (l <= r) range_add(1, l, r, v);
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query_max(1, l, r);
    }
} seg;

void sol() {
    last.clear();
    sci(n); sci(q);
    rep(i, 1, n) {
        sci(a[i]);
        maxR[i] = i;
    }
    rep(i, 1, n) {
        nxt[i] = 0;
        if (last.count(a[i])) {
            pre[i] = last[a[i]];
            nxt[pre[i]] = i;
        } else {
            pre[i] = -1;
        }
        last[a[i]] = i;
    }
    rep(i, 1, n) {
        if (nxt[i] == 0) {
            nxt[i] = n + 1;
        }
    }
    
    seg.init(n);
    
    int L = 1;
    rep(R, 1, n) {
        int p = pre[R];
        
       if (p != -1) {
            while (p != -1 && seg.query(p, p) > 0) {
                maxR[L] = max(maxR[L], R - 1);
                if (nxt[L] < R) { 
                    seg.add(L + 1, nxt[L] - 1, -1);
                }
                L++;
            }
            if (p >= L) {
                seg.add(p + 1, R - 1, 1);
            }
        }
        maxR[L] = max(maxR[L], R);
    }
    
    rep(i, L + 1, n) {
        maxR[i] = maxR[i - 1];
    }
    
    while (q--) {
        int l, r;
        sci(l); sci(r);
        if (maxR[l] >= r) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}

int main() {
    int t;
    sci(t);
    while (t--) {
        sol();
    }
    return 0;
}