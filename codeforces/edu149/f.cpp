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
typedef pair<int,int> P;
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
const int N=3e5+10;
int t,n,k,a[N];
ll pre[N],suf[N];
bool ok(ll x){
    {
        priority_queue<int>q;
        ll now=0;
        rep(i,1,n){
            q.push(a[i]);
            now+=a[i];
            while(!q.empty() && now>x){
                now-=q.top();
                q.pop();
            }
            pre[i]=SZ(q);
        }
    }
    {
        priority_queue<int>q;
        ll now=0;
        per(i,n,1){
            suf[i]=SZ(q);
            q.push(a[i]);
            now+=a[i];
            while(!q.empty() && now>x){
                now-=q.top();
                q.pop();
            }
        }
    }
    rep(i,1,n){
        if(pre[i]+suf[i]>=k)return 1;
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        ll sum=0;
        rep(i,1,n){
            sci(a[i]);
            sum+=a[i];
        }
        ll l=1,r=sum,ans=sum;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ok(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        ptlle(ans);
    }
    return 0;
}
