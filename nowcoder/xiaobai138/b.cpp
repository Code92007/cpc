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
const int N=5e5+10;
int t,n;
char s[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        bool no=0,yes=1,can=0;
        for(int i=1;i<=n+1-i;++i){
            int r=n+1-i;
            if(i==r)break;
            if(s[i]==s[r]){
                if(s[i]=='?'){
                    can=1;
                }
                continue;
            }
            if(s[i]=='?' || s[r]=='?'){
                can=1;
                continue;
            }
            no=1;
            yes=0;
            break;
        }
        if(no)puts("impossible");
        else if(can)puts("possible");
        else puts("certainly");
    }
    return 0;
}