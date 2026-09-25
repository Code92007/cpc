#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const int MAXL = 2000000 + 5;
const int MAXN = 200000 + 5;
const int MAXP = 200000 + 5;
const int MAXS = MAXL * 2;
const int MAXE = MAXL * 3;

struct FastIO {
    static const int B = 1 << 20;
    int p = 0, n = 0, op = 0;
    char ib[B], ob[B];

    inline char gc() {
        if (p == n) {
            n = fread(ib, 1, B, stdin);
            p = 0;
            if (!n) return 0;
        }
        return ib[p++];
    }

    int readInt() {
        char c = gc();
        while (c <= ' ') c = gc();
        int x = 0;
        while (c > ' ') {
            x = x * 10 + c - '0';
            c = gc();
        }
        return x;
    }

    int readWord(char *s) {
        char c = gc();
        while (c <= ' ') c = gc();
        int len = 0;
        while (c > ' ') {
            s[len++] = c;
            c = gc();
        }
        return len;
    }

    inline void pc(char c) {
        if (op == B) flush();
        ob[op++] = c;
    }

    void writeInt(int x) {
        if (!x) {
            pc('0');
            pc('\n');
            return;
        }
        char s[12];
        int len = 0;
        while (x) {
            s[len++] = char('0' + x % 10);
            x /= 10;
        }
        while (len) pc(s[--len]);
        pc('\n');
    }

    void flush() {
        if (op) {
            fwrite(ob, 1, op, stdout);
            op = 0;
        }
    }

    ~FastIO() {
        flush();
    }
} io;

int head[MAXS], to[MAXE], nxt[MAXE];
int fa[MAXS], slen[MAXS], occ[MAXS];
int ord[MAXS], cnt[MAXL];
uint32_t maskv[MAXS];
unsigned char edgec[MAXE];

int st[MAXN], plen[MAXN];
char pool[MAXP], text[MAXL];

struct SAM {
    int tot = 1, last = 1, ecnt = 0;

    inline bool hasEdge(int u, int c) {
        return maskv[u] & (1u << c);
    }

    inline int edgeId(int u, int c) {
        if (!(maskv[u] & (1u << c))) return 0;
        for (int e = head[u]; e; e = nxt[e]) {
            if (edgec[e] == c) return e;
        }
        return 0;
    }

    inline void addEdge(int u, int c, int v) {
        ++ecnt;
        to[ecnt] = v;
        edgec[ecnt] = (unsigned char)c;
        nxt[ecnt] = head[u];
        head[u] = ecnt;
        maskv[u] |= 1u << c;
    }

    void add(int c) {
        int p = last;
        int cur = last = ++tot;

        slen[cur] = slen[p] + 1;
        occ[cur] = 1;

        while (p && !hasEdge(p, c)) {
            addEdge(p, c, cur);
            p = fa[p];
        }

        if (!p) {
            fa[cur] = 1;
            return;
        }

        int q = to[edgeId(p, c)];

        if (slen[q] == slen[p] + 1) {
            fa[cur] = q;
            return;
        }

        int clone = ++tot;
        slen[clone] = slen[p] + 1;
        fa[clone] = fa[q];
        occ[clone] = 0;
        head[clone] = 0;
        maskv[clone] = maskv[q];

        for (int e = head[q]; e; e = nxt[e]) {
            ++ecnt;
            to[ecnt] = to[e];
            edgec[ecnt] = edgec[e];
            nxt[ecnt] = head[clone];
            head[clone] = ecnt;
        }

        fa[q] = fa[cur] = clone;

        while (p) {
            int e = edgeId(p, c);
            if (!e || to[e] != q) break;
            to[e] = clone;
            p = fa[p];
        }
    }

    void buildOcc(int n) {
        for (int i = 1; i <= tot; ++i) ++cnt[slen[i]];
        for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
        for (int i = tot; i >= 1; --i) ord[cnt[slen[i]]--] = i;

        for (int i = tot; i > 1; --i) {
            int u = ord[i];
            occ[fa[u]] += occ[u];
        }
    }

    int query(char *s, int len) {
        int u = 1;
        for (int i = 0; i < len; ++i) {
            int e = edgeId(u, s[i] - 'a');
            if (!e) return 0;
            u = to[e];
        }
        return occ[u];
    }
} sam;

int main() {
    int n = io.readInt();

    int top = 0;
    for (int i = 1; i <= n; ++i) {
        st[i] = top;
        plen[i] = io.readWord(pool + top);
        top += plen[i];
    }

    int len = io.readWord(text);

    for (int i = 0; i < len; ++i) {
        sam.add(text[i] - 'a');
    }

    sam.buildOcc(len);

    for (int i = 1; i <= n; ++i) {
        io.writeInt(sam.query(pool + st[i], plen[i]));
    }

    return 0;
}
