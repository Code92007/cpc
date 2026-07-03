//#include<bits/stdc++.h>
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
typedef pair<ll,int> P;
typedef array<int,3> A;
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
// w[i]=0的右侧，w[i+1]=h[i]
// w[i]=0的左侧，w[i-1]=h[i-1]
// max(w[i],2)>1，w[i]=2
// w[i]=max(h[i],w[i+1]) 0往前递推
// w[i+1]=min(h[i]) 0往后递推
const int N=6e3+10,INF=0x3f3f3f3f;
int t,n,h[N],L[N],R[N];
ll ans[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(h[i]);
            h[i+n]=h[i];
        }
        h[0]=h[n];
        h[2*n+1]=h[1];
        rep(x,1,n){
            int l=x,r=x+n-1; 
            L[r]=R[r]=R[r-n]=0;
            for(int i=r-1;i>=l;--i){
                L[i]=max(L[i+1],h[i]);
            }
            for(int i=l;i<r;++i){
                R[i]=max(R[i-1],h[i-1]);
            }
            ll res=0;
            for(int j=l;j<r;++j){
                res+=min(L[j],R[j]);
            }
            if(r>n)r-=n;
            ans[r]=res;
        }
        rep(i,1,n){
            printf("%lld%c",ans[i]," \n"[i==n]);
        }
    }
    return 0;
}