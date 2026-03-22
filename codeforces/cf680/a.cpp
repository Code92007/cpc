#include<bits/stdc++.h>
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
int t;
ll p,q;
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld",&p,&q);
        if(p%q==0){
            ll y=q;
            vector<int>res;
            for(int i=2;i*i<=q;++i){
                if(q%i==0){
                    res.pb(i);
                    while(q%i==0)q/=i;
                }
            }
            if(q>1)res.pb(q);
            ll ans=1;
            for(auto &v:res){
                ll x=p;
                while(x%y==0)x/=v;
                ans=max(ans,x);    
            }
            printf("%lld\n",ans);
        }
        else{
            printf("%lld\n",p);
        }
    }
    return 0;
}