#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long;
using u32 = unsigned;
using i64 = long long;
using i32 = signed;

template <i32 MOD>
u32 down(u32 x) { return x >= MOD ? x - MOD : x; }

template <i32 MOD>
struct MInt {
    u32 x;
    MInt () : x(0) {}
    MInt (u32 x) : x(x) {}
    friend MInt operator+(MInt a, MInt b) { return down<MOD>(a.x + b.x); }
    friend MInt operator-(MInt a, MInt b) { return down<MOD>(a.x - b.x + MOD); }
    friend MInt operator*(MInt a, MInt b) { return 1ULL * a.x * b.x % MOD; }
    friend MInt operator/(MInt a, MInt b) { return a * ~b; }
    friend MInt operator^(MInt a, i64 b) {
        MInt ans = 1;
        while (b) {
            if (b & 1) ans = ans * a;
            a = a * a;
            b /= 2;
        }
        return ans;
    }
    friend MInt operator~(MInt a) { return a ^ (MOD - 2); }
    // friend MInt operator~(MInt a) { return MInt(INV::inv(a.x)); }
    friend std::istream &operator>>(std::istream &in, MInt &a) { return in >> a.x; }
    friend std::ostream &operator<<(std::ostream &out, MInt a) { return out << a.x; }
    friend MInt operator-(MInt a) { return down<MOD>(MOD - a.x); }
    friend MInt &operator+=(MInt &a, MInt b) { return a = a + b; }
    friend MInt &operator-=(MInt &a, MInt b) { return a = a - b; }
    friend MInt &operator*=(MInt &a, MInt b) { return a = a * b; }
    friend MInt &operator/=(MInt &a, MInt b) { return a = a / b; }
    friend MInt &operator^=(MInt &a, long long b) { return a = a ^ b; }
    friend bool operator==(MInt a, MInt b) { return a.x == b.x; }
    friend bool operator!=(MInt a, MInt b) { return !(a == b); }
    friend bool operator<(MInt a, MInt b) { return a.x < b.x; }
};

const i32 MOD = 998244353;
using Z = MInt<MOD>;

mt19937_64 mrand(chrono::steady_clock().now().time_since_epoch().count());

struct Node {
    Node *l = nullptr;
    Node *r = nullptr;
    i64 val = 0;
    int st = 0;
    int sz = 1;
    int prio = 0;
    i64 add = 0;
    bool tag = 0;
    
    Node(){}
    Node (int _st, i64 _val) : st(_st), val(_val) {
        prio = mrand();

    }
    void pushup() {
        sz = 1;
        if (l != nullptr) sz += l->sz;
        if (r != nullptr) sz += r->sz;
    }

    void pushdown() {
        if (tag) {
            std::swap(l, r);
            if (l != nullptr) l->tag ^= 1;
            if (r != nullptr) r->tag ^= 1;
            tag = false;
        }
        if (add != 0) {
            if (l != nullptr) {
                l->val += add;
                l->add += add;
            }
            if (r != nullptr) {
                r->val += add;
                r->add += add;
            }
            add = 0;
        }
    }


} pool[1 << 23];

struct Treap {
    int idx = 0;

    Node* root = nullptr;
    Node* newnode(int st, i64 val) {
        pool[++idx] = Node(st, val);
        return &pool[idx];
    }

    int siz(Node *cur) {
        return cur == nullptr ? 0 : cur->sz;
    }


    std::pair<Node*, Node*> split(Node *cur, i64 val) {
        if (cur == nullptr) return {nullptr, nullptr};
        cur->pushdown();
        if (cur->val < val) {
            auto tmp = split(cur->r, val);
            cur->r = tmp.first;
            cur->pushup();
            return {cur, tmp.second};
        } else {
            auto tmp = split(cur->l, val);
            cur->l = tmp.second;
            cur->pushup();
            return {tmp.first, cur};
        }
    }

    Node* merge(Node *sm, Node *bg) {
        if (sm == nullptr) return bg;
        if (bg == nullptr) return sm;
        
        sm->pushdown();
        bg->pushdown();
        
        if (sm->prio < bg->prio) {
            sm->r = merge(sm->r, bg);
            sm->pushup();
            return sm;
        } else {
            bg->l = merge(sm, bg->l);
            bg->pushup();
            return bg;
        }
    }

    void insert(int st, i64 x) {
        auto [left, right] = split(root, x);
        
        if (right != nullptr) {
            right->val += x;
            right->add += x;
        }
        
        Node* now = newnode(st, x);
        
        root = merge(left, merge(now, right));
    }

    void dfs(Node* cur, vector<i64>& ans) {
        if (cur == nullptr) return;
        cur->pushdown();
        dfs(cur->l, ans);
        ans[cur->st] = cur->val;
        dfs(cur->r, ans);
    }

    void clear() {
        idx = 0;
        root = nullptr;
    }
} T;

void solve() {
    int n;
    cin >> n;
    
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    T.clear();

    for (int i = 1; i <= n; i++) {
        T.insert(i, a[i]);
    }
    
    vector<i64> ans(n + 1);
    T.dfs(T.root, ans);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}