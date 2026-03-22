#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
int n,m,a[N],v[N],id[N],par[N],sz[N],ans[3],res[N][3];
vector<int>in[N];
char s[5];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    par[v]=u;
    sz[u]+=sz[v];
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        par[i]=i;
        sz[i]=1;
    }
    sci(m);
    rep(i,1,m){
        sci(v[i]);
        scanf("%s",s);
        int p;
        if(s[0]=='C')p=0;
        else if(s[0]=='O')p=1;
        else p=2;
        id[i]=p;
        in[v[i]].pb(i);
    }
    rep(i,1,n){
        if(in[i].empty()){
            mer(a[i],i);
        }
    }
    rep(i,1,n){
        if(!in[i].empty()){
            int pos=in[i].back(),col=id[pos];
            ans[col]+=sz[i];
        }
    }
    per(i,m,1){
        int u=v[i];
        in[u].pop_back();
        rep(j,0,2){
            res[i][j]=ans[j];
        }
        int col=id[i],num=sz[u];
        ans[col]-=num;
        if(in[u].empty()){
            mer(a[u],u);
            if(!in[find(a[u])].empty()){
                int col2=id[in[find(a[u])].back()];
                ans[col2]+=num;
            }
        }
        else{
            int col2=id[in[u].back()];
            ans[col2]+=num;
        }
    }
    rep(i,1,m){
        rep(j,0,2){
            printf("%d%c",res[i][j]," \n"[j==2]);
        }
    }
    return 0;
}