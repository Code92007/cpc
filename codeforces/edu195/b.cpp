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
int t,n,f[N],g[N];
char s[N];
map<int,int>q;
int main(){
    sci(t);
    while(t--){
        scanf("%s",s+1);
        int ans=0;
        n=strlen(s+1);
        f[1]=1;
        rep(i,2,n){
            if(s[i]^s[i-1])f[i]=f[i-1]+1;
            else f[i]=f[i-1];
        }
        g[n]=1;
        per(i,n-1,1){
            if(s[i]^s[i+1])g[i]=g[i+1]+1;
            else g[i]=g[i+1];
        }
        q.clear();
        q[f[n]]=1;
        rep(i,2,n-1){
            if(s[i-1]^s[i+1])continue;
            if(s[i]==s[i-1]){//111
                q[f[i-1]+g[i+1]+1]=1;
            }
            else{//101
                q[f[i-1]+g[i+1]-1]=1;
            }
        }
        pte(SZ(q));
    }
    return 0;
}
//01010 01010 0101 010 101 01010