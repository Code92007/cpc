//#include<bits/stdc++.h>
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
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=1e6+10,K=20,M=2e7+10;
int n,m,cnt[N],tot;
bool vis[M],base[N];
ll ans;
int main(){
    sci(n),sci(m);
    for(int i=1;i<=20;++i){
        for(int j=1;j<=m;++j){
            if(vis[i*j])continue;
            tot++;
            vis[i*j]=1;
        }
        cnt[i]=tot;
    }
    for(int i=2;i<=n;++i){
        if(base[i])continue;
        int num=1;
        for(ll j=1ll*i*i;j<=n;j*=i){
            num++;
            base[j]=1;
        }
        ans+=cnt[num];
    }
    printf("%lld\n",ans+1);
    return 0;
}