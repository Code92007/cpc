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
const int N=2e5+10;
int t,n,m,u,v;
vector<int>e[N],ans;
char s[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);
        rep(i,1,n)e[i].clear();
        ans.clear();
        scanf("%s",s+1);
        rep(i,1,m){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        rep(i,1,n){
            int sum=0;
            for(auto &v:e[i]){
                int w=(s[v]=='0'?1:-1);
                sum+=w;
            }
            if(sum>0)ans.pb(i);
        }
        printf("%d\n",SZ(ans));
        for(auto &v:ans){
            printf("%d ",v);
        }
        puts("");
    }
    return 0;
}