//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<int,int> P;
typedef array<ll,4> A;
#define pb push_back
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=2e5+5;
int t,n,m,sz[N];
ll x;
vector<int>a[N],b[N];
vector<A>c;
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&x);
        c.clear();
        rep(i,1,n){
            sci(m);
            sz[i]=0;
            a[i].assign(m,0);
            b[i].assign(m,0);
            rep(j,0,m-1){
                sci(a[i][j]);
            }
            rep(j,0,m-1){
                sci(b[i][j]);
            }
            ll cur=0,mx=0;
            rep(j,0,m-1){
                mx=max(mx,1ll*a[i][j]-cur);
                cur+=1ll*b[i][j]-a[i][j];
                if(cur>0){
                    c.pb({mx,cur,i,j+1});
                    cur=0;
                }
            }
        }
        sort(c.begin(),c.end());
        for(auto [need,gain,id,pos]:c){
            if(x>=need){
                x+=gain;
                sz[id]=max(sz[id],(int)pos);
            }
        }
        P ans=P(0,-1);
        rep(i,1,n){
            int j=sz[i];
            ll now=x;
            while(j<SZ(a[i]) && now>=a[i][j]){
                now+=b[i][j]-a[i][j];
                ++j;
            }
            if(P(j,-i)>ans){
                ans=P(j,-i);
            }
        }
        printf("%d %d\n",ans.first,-ans.second);
    }
    return 0;
}