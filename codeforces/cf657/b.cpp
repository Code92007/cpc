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
const int N=2e5+10;
int n,k,ans;
ll a[N],b[N];
int main(){
    sci(n),sci(k);
    rep(i,0,n){
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    rep(i,0,n){
        if(a[i]>0){
            a[i+1]+=a[i]/2;
            a[i]%=2;
        }
        else{
            if(a[i]&1){//-3 借2转成1
                a[i+1]+=(a[i]-1)/2;
                a[i]=1;
            }
            else{//-4 借2转成0
                a[i+1]+=a[i]/2;
                a[i]=0;
            }
        }
    }
    int r=0;
    rep(i,0,n){//311110000 维护1和0的分界处1的位置
        if(a[i]==0)r=i+1;
        else break;
    }
    r=min(r,n);
    ll now=0;
    per(i,n+1,0){
        now=2*now+a[i];
        if(abs(now)>2*k)break;
        if(i<=r){//要把b[i]减少now 这样最终是0
            ll v=b[i]-now;//b[i]∈[-k,k] now∈[-2k,2k] now超出后，v一定不在[-k,k]范围内
            if(i==n && v==0)continue;
            if(abs(v)<=k)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}