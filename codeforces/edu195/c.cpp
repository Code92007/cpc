//#include<bits/stdc++.h>
#include<iostream>
#include<map>
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
const int N=3e5+10;
int t,n,k,a[N];
ll sum[N];
map<ll,int>q;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        ll ans=0;
        rep(i,1,n){
            sci(a[i]);
            sum[i]=(sum[i-1]+a[i])%k;
            if(q.count(sum[i]))ans+=q[sum[i]];
            if(i>=k)q[sum[i-k]]++;
        }
        ptlle(ans);
        q.clear();
    }
    return 0;
}
//01010 01010 0101 010 101 01010