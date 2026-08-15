//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
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

const int N = 505, M = 2 * N, mod = 998244353;
int n, a[M][N], used[N], cnt[N][N];
vector<int> ans;

void solve(){
    scanf("%d", &n);
    ans.clear();
    memset(used, 0, sizeof used);
    memset(cnt, 0, sizeof cnt);
    int m = 2 * n;
    rep(i, 1, m) {
        rep(j, 1, n) {
            scanf("%d", &a[i][j]);
            cnt[a[i][j]][j]++;
        }
    }
    int res = 1;
    rep(i, 1, n) {
        int cur = 0;
        rep(j, 1, m) {
            if(!used[j]) {
                rep(k, 1, n) {
                    if(cnt[a[j][k]][k] == 1) { 
                        cur = j; 
                        break; 
                    }
                }
                if(cur) break;
            }
        }
        if(!cur) {
            res = 2ll * res % mod;
            cur = 1;
            while(used[cur]) {
                cur++;
            }
        }
        used[cur] = 1;
        rep(j, 1, m) {
            if(!used[j]) {
                rep(k, 1, n) {
                    if(a[j][k] == a[cur][k]) { 
                        used[j] = 1; 
                        break; 
                    }
                }
                if(used[j]) {
                    rep(k, 1, n) {
                        cnt[a[j][k]][k]--;
                    }
                }
            }
        }
        rep(k, 1, n) {
            cnt[a[cur][k]][k]--;
        }
        ans.push_back(cur);
    }
    printf("%d\n", res);
    for(int y : ans) {
        printf("%d ", y);
    }
    puts("");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}