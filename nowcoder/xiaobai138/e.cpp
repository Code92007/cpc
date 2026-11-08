#include<bits/stdc++.h>
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
const int N=1e6+10;
int t,n;
char s[N];
int a[N],b[3];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        rep(i,1,n){
            if(s[i]=='R')a[i]=0;
            else if(s[i]=='S')a[i]=1;
            else a[i]=2;
        }
        memset(b,0,sizeof b);
        bool ok=0;
        rep(i,1,n){
            int w=(a[i]+2)%3;
            if(b[w])ok=1;
            b[a[i]]=1;
        }
        puts(ok?"Alice":"Bob");
    }
    return 0;
}