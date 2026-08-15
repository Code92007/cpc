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
const int N=2e3+10;
int t,n,m,d,a[N],b[N];
ll sum[N];
ll cal(ll x){
    if(x>n){
        ll w=x/n,v=x%n;
        return w*cal(n)+cal(v);
    }
    int p;
    if(x>=a[m])p=m;
    else p=upper_bound(a+1,a+m+1,x)-a-1;
    return 1ll*x*d+sum[p];
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(d);
        rep(i,1,m){
            sci(a[i]),sci(b[i]);
            sum[i]=sum[i-1]+b[i];
        }
        if(m==0){
            puts("NO");
            continue;
        }
        if(a[m]!=n){
            a[++m]=n;b[m]=0;
            sum[m]=sum[m-1];
        }
        bool ok=0;
        rep(i,1,m){
            ll cyc=a[i]+1,val=1ll*a[i]*d+sum[i];
            rep(j,i,m){
                //if(j+1<=m)days=a[j+1].fi-1;
                // auto can=[&](ll days){
                //     ll w=days/cyc,r=days%cyc;
                //     ll sum1=1ll*w*val+cal(r),sum2=cal(days);
                //     //printf("days:%lld sum1:%lld sum2:%lld\n",days,sum1,sum2);
                //     return sum1>sum2;
                // };
                // ok|=can(a[j]);
                // if(j+1<=m){
                //     ok|=can(a[j+1]-1);
                //     ll v=a[j+1]/cyc*cyc+a[i];
                //     while(v>=a[j+1])v-=cyc;
                //     if(v>=a[j])ok|=can(v);//11110111101111
                // }   
                ll sum1=cal(a[i])+cal(a[j]),sum2=cal(a[i]+1+a[j]);
                ok|=(sum1>sum2);
                // if(1ll*cal(a[i]+1+a[j])*n>1ll*cal(n)*(a[i]+2+a[j])){
                //     ok=1;
                // }
            }
        }
        // rep(i,1,m){
        //     if(1ll*cal(a[i]+1)*n>1ll*cal(n)*(a[i]+1)){
        //         ok=1;
        //     }
        // }
        puts(ok?"YES":"NO");
        // sort(a+1,a+m+1);
        // int c=0;
        // rep(i,1,m){
        //     if(!c)a[++c]=a[i];
        //     else{
        //         if(a[c].fi==a[i].fi)a[c].se+=a[i].se;
        //         else{
        //             a[++c]=a[i];
        //         }
        //     }
        // }
        //m=c;
    }
    return 0;
}
//9天59 4天27 3天26
//3天30 7天60 10天90 13天120