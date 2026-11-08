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
int T,n,m;
char a[N],b[N];
vector<ll>cal(char *s,char *t,int n,int m){
    int las=-1,cnt=0;
    vector<int>del(m+1,0);
    vector<int>suf(m+2,0);
    suf[m+1]=0;
    vector<ll>ans;
    per(i,m,1){
        suf[i]=suf[i+1]+(t[i]=='W');
    }
    rep(i,1,m){
        if(t[i]=='W'){
            cnt++;
            if(~las)del[i-las]++;
            las=i;
        }
    }
    bool hasW=0;
    int j=-1;
    ll now=0;
    rep(i,1,n){
        if(s[i]=='W'){
            hasW=1;
            j=i;
            continue;
        }
        if(!hasW){
            now+=cnt;
            if(i<=m)cnt-=del[i];
            ans.pb(1+now);
        }
        else{
            now=m+1;
            now+=suf[min(m+1,j+m-(i-1)+1)];
            ans.pb(now);
        }
    }
    return ans;
}
int main(){
    sci(T);
    while(T--){
        sci(n),sci(m);
        scanf("%s%s",a+1,b+1);
        auto x=cal(a,b,n,m);
        auto y=cal(b,a,m,n);
        for(auto &v:x)printf("%lld ",v);puts("");
        for(auto &v:y)printf("%lld ",v);puts("");
    }
    return 0;
}
/*
alice不能走叶子 只能往偶度点上走
*/