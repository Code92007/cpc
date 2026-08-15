//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<random>
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
const int N=5e3+10;
int t,n,a[N],pos[N];
vector<int>ans;
void op(int x){
    ans.pb(x);
    int lef=a[x],rig=a[x+1];
    per(i,x,2)a[i]=a[i-1];
    a[1]=lef;
    rep(i,x+1,n-1)a[i]=a[i+1];
    a[n]=rig;
    rep(i,1,n)pos[a[i]]=i;
    // puts("op:");
    // rep(i,1,n){
    //     printf("%d ",a[i]);
    // }
    // puts("");
}
void sol(){
    ans.clear();
    rep(i,1,n){
        sci(a[i]);
        pos[a[i]]=i;
    }
    rep(i,2,n-1){
        if(pos[i]>1){
            op(pos[i]-1);
        }
        else{
            op(2);
            op(1);
            op(n-1);
        }
    }
    if(pos[n]==1){
        if(n%2==0){
            puts("-1");
            return;
        }
        rep(i,1,n-2){
            op(2);
        }
    }
    op(1);
    pte(SZ(ans));
    for(auto &v:ans){
        printf("%d ",v);
    }
    puts("");
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        sol();
    }
    return 0;
}