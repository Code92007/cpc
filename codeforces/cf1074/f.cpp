#include<bits/stdc++.h>
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
const int N=19,M=(1<<18)+10,Q=2e5+10;
int t,n,q,a[M],sum[M],b,c;
int cal(int l,int r){
    if(l==0)return sum[r];
    return sum[r]^sum[l-1];
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        int m=1<<n;
        rep(i,0,m-1){
            sci(a[i]);
            if(i)sum[i]=sum[i-1]^a[i];
            else sum[i]=a[i];
        }
        while(q--){
            sci(b),sci(c);
            b--;
            int L,R,lb,rb,ans=0;
            rep(i,0,n-1){
                int len=1<<i;
                if(i==0)L=b,R=b;
                else L=min(lb,L),R=max(rb,R);
                lb=L^len,rb=R^len;
                if(lb>rb)swap(lb,rb);
                int x=cal(L,R)^a[b]^c,y=cal(lb,rb);
                if(x>y || (x==y && L<lb)){
                    continue;
                }
                ans+=rb-lb+1;
            }
            pte(ans);
        }
    }
    return 0;
}