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
//思路:折半枚举 枚举副对角线的格子，对于左上和右下的方案暴力dfs
const int N=25;
int n,m;
ll k,a[N][N],ans;
map<ll,ll>cnt1,cnt2;
void dfs(int x,int y,ll w){
    if(x==1 && y==1){
        cnt1[w]++;
        return;
    }
    if(x>1)dfs(x-1,y,w^a[x-1][y]);
    if(y>1)dfs(x,y-1,w^a[x][y-1]);
}
void dfs2(int x,int y,ll w){
    if(x==n && y==m){
        cnt2[w]++;
        return;
    }
    if(x<n)dfs2(x+1,y,w^a[x+1][y]);
    if(y<m)dfs2(x,y+1,w^a[x][y+1]);
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        int l=i,r=m+1-i;
        if(r<1)break;
        cnt1.clear();
        cnt2.clear();
        dfs(l,r,a[l][r]);
        dfs2(l,r,a[l][r]);
        ll w=a[l][r]^k;
        for(auto &v:cnt1){
            ll ano=w^v.fi;
            if(cnt2.count(ano)){
                ans+=1ll*v.se*cnt2[ano];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}