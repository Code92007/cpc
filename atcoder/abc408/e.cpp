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
const int N=3e5+10;
int n,m,par[N];
bool ban[N];
A a[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    par[v]=u;
}
int main(){
    sci(n),sci(m);
    rep(i,1,m){
        rep(j,0,2){
            sci(a[i][j]);
        }
    }
    int ans=0;
    per(i,29,0){
        rep(j,1,n)par[j]=j;
        rep(j,1,m){
            int u=a[j][0],v=a[j][1],w=a[j][2];
            if(ban[j])continue;
            if(!(w>>i&1))mer(u,v);
        }
        if(find(1)!=find(n))ans|=1<<i;
        else{
            rep(j,1,m){
                int w=a[j][2];
                if(w>>i&1)ban[j]=1;
            }
        }
    }
    pte(ans);
    return 0;
}