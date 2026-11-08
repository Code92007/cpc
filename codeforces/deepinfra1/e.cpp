//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int N=2e5+10;
int t,n,k,a[N];
map<int,int>q;
bool ok(int x){
    int operations = x - k;
    if (operations < n) return false;
    int budget = (operations - n) / 2;
    // 把操作次数向下调整为 n + 2 * budget。
    x = k + n + 2 * budget - 1;
    q.clear();
    rep(i,1,n){
        q[a[i]]++;
    }
    int splits=0;
    per(i,x,k){
        if(!SZ(q))return i-k+1>=splits;
        while((*q.rbegin()).fi>i){
            P z=*q.rbegin();
            int v=z.fi,cnt=z.se;
            int nv=(v+1)/2;
            if(v==nv)return 0;
            splits+=cnt;
            if(splits>=3*n)return 0;
            q.erase(v);
            q[nv]+=2*cnt;
        }
        P z=*q.rbegin();
        int v=z.fi,cnt=z.se;
        if(cnt==1)q.erase(v);
        else q[v]--;
        if(!SZ(q))return i-k>=splits;
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        rep(i,1,n){
            sci(a[i]);
        }
        int l=k+1,r=3*n+5,ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(ok(mid))ans=mid-k,r=mid-1;
            else l=mid+1;
        }
        pte(ans);
    }
    return 0;
}