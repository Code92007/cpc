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
const int N=1e5+10,INF=0x3f3f3f3f;
char s[N];
int n,sum[N];
void add(int l,int r){
    if(l>n || r<=0 || l>r)return;;
    l=max(1,l),r=min(r,n);
    sum[l]++,sum[r+1]--;
}
bool ok(int x){
    if(x==1)return 1;
    memset(sum,0,sizeof sum);
    int las=-1;
    rep(i,1,n){
        if(s[i]=='1'){//[i-x+1,i-1]i[i+1,i+x-1]
            add(i-x+1,i+x-1);
            if(~las && i-las<x)return 0;
            las=i;
        }
    }
    int mn=INF,mx=-INF;
    rep(i,1,n){
        sum[i]+=sum[i-1];
        if(sum[i]>0)continue;
        mn=min(mn,i);
        mx=max(mx,i);
    }
    return mx-mn>=x;
}
int main(){
    scanf("%d%s",&n,s+1);
    int l=1,r=n-1,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(ok(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}