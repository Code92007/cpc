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
const int N=3e5+10,M=20;
int t,n,u,v,par[N];
bool used[N];
vector<int>e[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int op(int x){
    rep(i,1,n){
        used[i]=0;
    }
    rep(i,1,n){
        if(1<=x-i && x-i<=n && i!=x-i){
            used[i]=used[x-i]=1;
        }
    }
    rep(i,1,n)par[i]=i;
    rep(i,1,n){
        if(!used[i])continue;
        for(auto &v:e[i]){
            if(!used[v])continue;
            par[find(v)]=find(i);
        }
    }
    rep(i,1,n){
        if(1<=x-i && x-i<=n && i!=x-i){
            if(find(i)!=find(x-i))return 1;
        }
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)e[i].clear();
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        if(n%2==0)pte(n+1);
        else{
            int ans=n;
            for(auto w:{n,n+1,n+2}){
                if(op(w)){
                    ans=w;
                    break;
                }
            }
            pte(ans);
        }
    }
    return 0;
}