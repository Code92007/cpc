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
const int N=1e5+10,mod=998244353;
int t,n;
ll v;
char s[N];
int main(){
    sci(t);
    while(t--){
        scanf("%s",s);
        n=strlen(s);
        v=0;
        rep(i,0,n-1){
            int w=s[i]-'0';
            v=(9ll*v+w)%mod;
        }
        printf("%lld\n",v);
    }
    return 0;
}