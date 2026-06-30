#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
typedef array<ll,3> A;
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

const db eps = 1e-9;
const int N = 1e6 + 5;

db f[N << 1][2];
int n, tot;
char s[N], w[N << 1];

bool check(db mid) {
    f[0][0] = -mid, f[0][1] = 0;
    rep(i, 1, tot) {
        f[i][0] = f[i - 1][1] + (w[i] == 'L') - mid;
        f[i][1] = f[i - 1][0] + (w[i] == 'R') - mid;
        f[i][0] = max(f[i][0], f[i][1] - mid);
        f[i][1] = max(f[i][1], f[i][0] - mid);
    }
    return f[tot][1] >= 0;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (s[1] == s[n] && s[1] == 'R') {// 如果RXXR，循环序列RXXRRXXR相邻，需要开头补X
        w[++tot] = 'X';
    }
    rep(i, 1, n) {
        if (s[i] == s[i - 1] && s[i] != 'X') {
            w[++tot] = 'X';
        }
        w[++tot] = s[i];
    }
    if (s[1] == s[n] && s[1] == 'L') {//同理LXXL，LXXLLXXL，需要结尾补X
        w[++tot] = 'X';
    }
    db l = 0, r = 100;
    while (fabs(l - r) > eps) {
        db mid = (l + r) / 2;
        if (check(mid / 100)) l = mid;
        else r = mid;
    }
    printf("%.6lf", (int)(r * 1e6) / (1e6)); // 这里没有spj，所以需要这么处理
    return 0;
}