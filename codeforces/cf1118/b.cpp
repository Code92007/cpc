//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10,K=2e5;
int t,n,m,a[N],cnt[N];
ll res[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,m){
            cnt[i]=0;
        }
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
        }
        rep(i,1,m){
            cnt[i]+=cnt[i-1];
        }
        int las=0;
        rep(i,1,18){
            ll ans=0;   
            int x=1<<i;
            if(x>2*m)break;
            las=i;
            rep(j,1,m){
                int up=min(1ll*x*j,1ll*m);
                ll all=0;
                for(int k=j;k<=up;k+=j){
                    int r=min(k+j-1,up);
                    int num=cnt[r]-cnt[k-1];
                    all+=1ll*(k/j)*num;
                }
                all+=1ll*(n-cnt[up])*(x-1);
                ans=max(ans,all);
            }
            res[i]=ans;
        }
        m=1;
        rep(i,1,m){
            if(i>las)res[i]=res[i-1];
            printf("%lld%c",res[i]," \n"[i==m]);
        }
    }
    return 0;
}