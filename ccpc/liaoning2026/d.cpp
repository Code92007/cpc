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
const int N=5e5+10,M=1e7+10,K=2e6+10;
int t,n,a[N],d[M],pr[M],tot;
int sol(){
    rep(i,1,n){
        if(1<=a[i] && a[i]<=3)return -1;
        if(a[i]==5 || a[i]==7)return -1;
    }
    int ans=0;
    rep(i,1,n){
        if(a[i]==0)continue;
        int v=a[i];
        //printf("i:%d a:%d di:%d\n",i,a[i],d[a[i]]);
        if(d[v]==v)ans+=2;
        else ans++;
    }
    return ans;
}
int main(){
    for(int i=2;i<M;++i){
		if(!d[i]){
            pr[tot++]=d[i]=i;
            //if(i<=100)printf("i:%d\n",i);
        }
		for(ll j=0,k;(k=1ll*i*pr[j])<M;++j){
		    d[k]=pr[j];
		    if(d[i]==pr[j])break;
		}
        //if(i<=50)printf("i:%d d:%d\n",i,d[i]);
	}
    sci(t);
    int st=0;
    //assert(1<=t && t<=500000);
    while(t--){
        sci(n);
        st+=n;
        //assert(1<=n && n<=500000);
        rep(i,1,n){
            sci(a[i]);
            //assert(0<=a[i] && a[i]<=10000000);
        }
        pte(sol());
    }
    //assert(0<=st && st<=500000);
    return 0; 
}