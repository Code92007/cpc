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
const int N=3e3+10;
int t,n,a[N],id[N];
vector<int>b[N],tmp,ans;
map<int,int>vis;
bool cmp(int x,int y){
    vector<int>&l=b[x];
    vector<int>&r=b[y];
    int sz=min(SZ(l),SZ(r));
    rep(i,0,sz-1){
        if(l[i]<r[i])return 1;
        if(l[i]>r[i])return 0;
    }
    if(SZ(l)<SZ(r))return 1;
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            b[i].clear();
            sci(a[i]);
            rep(j,1,a[i]){
                int v;
                sci(v);
                b[i].pb(v);
            }
            reverse(b[i].begin(),b[i].end());
            tmp.clear();
            vis.clear();
            for(auto &v:b[i]){
                if(vis.count(v))continue;
                vis[v]=1;
                tmp.pb(v);
            }
            b[i].swap(tmp);
        }
        rep(i,1,n)id[i]=i;
        sort(id+1,id+n+1,cmp);
        vis.clear();
        rep(i,1,n){
            int p=id[i];
            for(auto &v:b[p]){
                //if(vis.count(v))continue;
                vis[v]=1;
                ans.pb(v);   
            }
            rep(j,i+1,n){
                int q=id[j];
                tmp.clear();
                for(auto &v:b[q]){
                    if(vis.count(v))continue;
                    tmp.pb(v);
                }
                b[q].swap(tmp);
            }
            sort(id+i+1,id+n+1,cmp);
        }
        for(auto &v:ans){
            printf("%d ",v);
        }
        puts("");
        ans.clear();
    }
    return 0;
}