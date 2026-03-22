#include <iostream>
using namespace std;
typedef long long ll;
int n, m;
struct SegNode {
    int llen, rlen, val;
} f[400005];
int Calc(int x) { return (x + 1) / 2; }
void Pushup(SegNode &s, const SegNode &ls, const SegNode &rs, int l, int mid, int r) {
    s.llen = ls.llen;
    if (s.llen == mid - l + 1) s.llen += rs.llen;
    s.rlen = rs.rlen;    
    if (s.rlen == r - mid) s.rlen += ls.rlen;
    s.val = ls.val + rs.val - Calc(ls.rlen) - Calc(rs.llen) + Calc(ls.rlen + rs.llen);
}
void Modify(int p, int l, int r, int i, int w) {
    if (l == r) {
        f[p].llen = f[p].rlen = f[p].val = w;
        return;
    }
    int mid = l + r >> 1;
    if (i <= mid) Modify(p << 1, l, mid, i, w);
    else Modify(p << 1 | 1, mid + 1, r, i, w);
    Pushup(f[p], f[p << 1], f[p << 1 | 1], l, mid, r);
}
struct Element {
    int val, id;
    bool operator<(const Element &o) const { return val < o.val; }
} a[100005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].id = i;
    sort(a + 1, a + n + 1);
    int res = 1e9;
    int l = 1, r = 0;
    while (l <= n) {
        while (r <= n && f[1].val < m) {
            if (++r <= n) Modify(1, 1, n, a[r].id, 1);
        }
        if (r <= n) res = min(res, a[r].val - a[l].val);
        else break;
        printf("l:%d r:%d res:%d\n",l,r,res);
        Modify(1, 1, n, a[l].id, 0);
        l++;
    }
    printf("%d\n", res);
    return 0;
}
/*
4 2
100 1 10 1000 

枚举1作为最小值的时候，
1不一定是必选的
所以才可以双指针
1如果选 有(1,1000)(10,100)
序列就违背了单调不减的原则
*/
