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
const int N=5e5+10,mod=998244353;
int t,n,a[N],cnt[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        if(n>N-10)while(1);
        bool ok=1;
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
            ok&=(a[i]==i);
        }
        ll ans=0;
        rep(i,1,n){
            if(cnt[i]!=1)while(1);
            if(a[i]==i)ans+=n-i;
            else break;
        }
        rep(i,1,n)cnt[i]=0;
        ans+=ok;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}