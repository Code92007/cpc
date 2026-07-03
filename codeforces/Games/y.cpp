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
const int N=1e5+10,M=1e6+10,K=10;
// 注意到 sg[i]={sg[sqrt(i)]}+1 几次开方就开到1了 所以sg<=10
int n,sg[M];
ll v;
bool vis[K];
vector<int>w[M];
int cal(ll i){
    int l=sqrt(sqrt(i)),r=sqrt(i);
    if(r>=i)r=i-1;
    while(1ll*l*l*l*l<i)l++;
    //if(i<=3)printf("i:%lld l:%d r:%d\n",i,l,r);
    if(l>r)return 0;
    memset(vis,0,sizeof vis);
    rep(j,0,9){
        auto it=lower_bound(w[j].begin(),w[j].end(),l);
        if(it!=w[j].end() && (*it)<=r){
            vis[j]=1;
        }
    }
    rep(j,0,9){
        if(!vis[j]){
            return j;
        }
    }
    return 10;
}
void init(){
    int up=1e6;
    rep(i,1,up){
        sg[i]=cal(i);
        // if(i<=2){
        //     printf("i:%d sg:%d\n",i,sg[i]);
        // }
        w[sg[i]].pb(i);
    }
}
int main(){
    init();
    sci(n);
    int ans=0;
    rep(i,1,n){
        scanf("%lld",&v);
        ans^=cal(v);
    }
    puts(ans?"Furlo":"Rublo");
    return 0;
}