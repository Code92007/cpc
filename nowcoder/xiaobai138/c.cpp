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
int t,n,k,v;
map<int,int>mp;
P ans;
int main(){
    sci(t);
    while(t--){
        sci(n);sci(k);
        ans=P(-1,-1);
        mp.clear();
        rep(i,1,n){
            sci(v);
            if(ans.fi==-1){
                if(mp.count(k-v)){
                    ans=P(mp[k-v],i);
                }
            }
            mp[v]=i;
        }
        if(ans.fi==-1)puts("-1");
        else printf("%d %d\n",ans.fi,ans.se);
    }
    return 0;
}