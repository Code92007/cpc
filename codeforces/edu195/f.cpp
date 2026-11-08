//#include<bits/stdc++.h>
#include<iostream>
#include<map>
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
const int N=2e5+10;
int t,n,k,p[N],cnt[22];
bool vis[N];
bool sol(){
    vector<int>all;
    rep(i,1,n){
        if(vis[i])continue;
        int cnt=0;
        for(int j=i;!vis[j];j=p[j]){
            vis[j]=1;
            cnt++;
        }
        all.pb(cnt);
    }
    sort(all.begin(),all.end());
    if(all.back()>k+1)return 0;
    memset(cnt,0,sizeof cnt);
    for(auto &v:all){
        cnt[v]++;
    }
    int now=k;
    per(i,20,1){
        if(!cnt[i])continue;
        if(now>=i){
            now-=i;
            cnt[i]--;
        }
    }
    int left=0,now2=k;
    per(i,20,1){
        if(!cnt[i])continue;
        int w=min(now2,cnt[i]);
        left+=1ll*(i-1)*w;
        if(left>k)return 0;
        now2-=cnt[i];
    }
    if(cnt[k+1]==1 && (cnt[1]%2==1))return 1;
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        rep(i,1,n){
            sci(p[i]);
            vis[i]=1;
        }
        puts(sol()?"Alice":"Bob");
    }
    return 0;
}
//1 2 3 4 0 0
//1 1 1 1 -4 0
//1 0 0 0 -5 4