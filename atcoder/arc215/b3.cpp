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
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=2e5+10,M=2*N;
int t,n,a[M],b[M];
vector<int>pos[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            pos[i].clear();
        }
        rep(i,1,2*n){
            sci(a[i]);
            pos[a[i]].pb(i);
        }
        rep(i,1,n){
            int x=pos[i][0],y=pos[i][1];
            b[x]=0;b[y]=1;
        }
        vector<int>res,ans;
        rep(i,2,2*n){
            if(b[i]!=b[i-1])res.pb(i-1);
            else ans.pb(i-1);
        }
        if(SZ(res)>SZ(ans))swap(ans,res);
        pte(SZ(res));
        for(auto &v:res){
            printf("%d ",v);
        }
        puts("");
    }
    return 0;
}