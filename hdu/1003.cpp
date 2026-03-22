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
const int N=2e3+10;
int T,n,lcp[N][N],lef[N],rig[N];
char s[N],t[N];
bool is[N][N],it[N][N];
ll sol(){
    ll ans=0;
    n=strlen(s+1);
    rep(i,1,n){
        lef[i]=rig[i]=0;
        is[i][i]=it[i][i]=1;
        if(i+1<=n){
            is[i][i+1]=(s[i]==s[i+1]);
            it[i][i+1]=(t[i]==t[i+1]);
        }
    }
    rep(len,3,n){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            is[l][r]=is[l+1][r-1] && (s[l]==s[r]);
            it[l][r]=it[l+1][r-1] && (t[l]==t[r]);
        }
    }
    rep(i,1,n){
        per(j,n,1){
            int w=(s[i]==t[j]?1:0);
            if(i==1 || j==n)lcp[i][j]=w;
            else lcp[i][j]=lcp[i-1][j+1]+w;
            ans+=lcp[i][j];
            lef[i]+=lcp[i][j];
            rig[j]+=lcp[i][j];
        }
    }
    rep(l,1,n){
        rep(r,l,n){
            if(is[l][r])ans+=lef[l-1];
            if(it[l][r])ans+=rig[r+1];
        }
    }
    return ans;
}
int main(){
    sci(T);
    while(T--){
        scanf("%s%s",s+1,t+1);
        printf("%lld\n",sol());
    }
    return 0;
}
/*
ba ab

cdaba dcaba
cdabba dc
cd abbadc
*/