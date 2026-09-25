#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long i64;

const i64 linf = 4e18;
int n, q, x;

struct Matrix {
    i64 a[100];
};

Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            i64 ret = linf;
            for(int k = 0; k < x; k++) {
                ret = min(ret, A.a[i * x + k] + B.a[k * x + j]);
            }
            C.a[i * x + j] = ret;
        }
    }
    return C;
}

Matrix id() {
    Matrix A;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            A.a[i * x + j] = (i == j ? 0 : linf);
        }
    }
    return A;
}

Matrix make_matrix(int d, int s) {
    Matrix A;
    for(int i = 0; i < x; i++) {
        int p = -x + 1 + i;
        for(int j = 0; j < x; j++) {
            int t = d - x + 1 + j;
            if(t <= 0) {
                A.a[i * x + j] = (p == t ? 0 : linf);
            } else {
                int cnt = (t - p + x - 1) / x - 1;
                A.a[i * x + j] = (i64)cnt * s;
            }
        }
    }
    return A;
}

struct SegTree {
    vector<Matrix> tr;
    vector<int> *d, *s;

    Matrix get(int p) {
        if(p >= n) {
            int id = p - n;
            return make_matrix((*d)[id], (*s)[id]);
        }
        return tr[p];
    }

    void build(vector<int> &_d, vector<int> &_s) {
        d = &_d;
        s = &_s;
        tr.resize(n);

        for(int i = n - 1; i >= 1; --i) {
            tr[i] = mul(get(i << 1), get(i << 1 | 1));
        }
    }

    void modify(int p) {
        p += n;
        while(p >>= 1) {
            tr[p] = mul(get(p << 1), get(p << 1 | 1));
        }
    }

    Matrix query(int l, int r) {
        Matrix L = id(), R = id();
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = mul(L, get(l++));
            if(r & 1) R = mul(get(--r), R);
        }
        return mul(L, R);
    }
} st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> x;

    vector<int> d(n), s(n);
    for(auto &v : d) cin >> v;
    for(auto &v : s) cin >> v;

    st.build(d, s);

    while(q--) {
        char op;
        cin >> op;

        if(op == '?') {
            int l, r;
            cin >> l >> r;
            Matrix ans = st.query(l - 1, r);
            cout << ans.a[x - 1] << endl;
        } else {
            int i, v;
            cin >> i >> v;
            --i;

            if(op == '1') d[i] = v;
            else s[i] = v;

            st.modify(i);
        }
    }

    return 0;
}
