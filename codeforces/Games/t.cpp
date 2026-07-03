//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
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
using namespace std;
typedef long long ll;
const int N=105;
struct mat {
    static const int MAXN=128;
    db c[MAXN][MAXN];
    int m, n;
    mat(){
    	memset(c, 0, sizeof(c));
    	m=n=MAXN;
    }
    mat(int a, int b) : m(a), n(b) {
        memset(c, 0, sizeof(c));
    }
    void clear(){
		memset(c, 0, sizeof(c));
    }
    mat operator * (const mat& temp) {
        mat ans(m, temp.n);
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < temp.n; j ++){
                for (int k = 0; k < n; k ++){
                    ans.c[i][j] += c[i][k] * temp.c[k][j];
                }
            }
        return ans;
    }
    mat operator ^(ll n){
        mat M(*this),ans(M.m, M.m);
    	for (int i = 0; i < M.m; i ++)
        ans.c[i][i] = 1;
   		while (n > 0) {
            if (n & 1) ans = ans * M;
            M = M * M;
            n >>= 1;
    	}
        return ans;
	}
}b,ans;
int n,x;
db p[N];
int main(){
    scanf("%lld%d",&n,&x);
    rep(j,0,x){
        scanf("%lf",&p[j]);
    }
    rep(i,0,127){
        rep(j,0,x){
            b.c[i][i^j]+=p[j];
        }
    }
    b=b^n;
    printf("%.8lf\n",1.-b.c[0][0]);
    return 0;
}