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
            if(~las)now += max(0, las + i - j - m - 1);
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
RWRRRR
RRRWWR
1. 对于6，同序列最后一个W在2，那么最小读到2，最大读到8
至少是m+1种值，还能比8大吗
1. 如果同序列前面有W
1base 对于i，上一个位于j，最小读到j，最大读到j+m
j+m-(i-1)+1后面每有一个w就产生一个贡献
2. 如果同序列前面没有W
那么6可以读到0
对面的W，假设在4，可以读到4、5、6、7、8、9，有[0,i-1]种值
i前面有i-1个R，6前面5个R，W位于[4,9] [5,10]是一个长为i的区间
i=1 [4][5] i=2 [4,5][5,6]
RRRRRR
RRRWRR
*/