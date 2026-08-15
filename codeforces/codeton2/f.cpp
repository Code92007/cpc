//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=5e5+10,M=105;
int t,n,sg[M];//有34的循环节 但在小数据有例外
char s[N];
bool vis[M];
void init(){
    sg[1]=0;
    int up=101;
    rep(i,2,up){
        memset(vis,0,sizeof vis);
        vis[sg[i-2]]=1;
        rep(j,1,i-3){
            vis[sg[j]^sg[i-2-j]]=1;
        }
        rep(j,0,up){
            if(!vis[j]){
                sg[i]=j;
                break;
            }
        }
        //printf("i:%d sg:%d\n",i,sg[i]);
    }
}
int f(int x){
    if(x<=101)return sg[x];
    x-=68;
    x%=34;
    x+=68;
    return sg[x];
}
bool sol(){
    int alice=0,bob=n;
    rep(i,1,n){
        if(s[i]=='R')alice++,bob--;
    }
    if(alice>bob)return 1;
    if(alice<bob)return 0;
    int now=1,ans=0;
    rep(i,2,n){
        if(s[i]!=s[i-1])now++;
        else ans^=f(now),now=1;
    }
    ans^=f(now);
    return ans;
}
int main(){
    init();
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        puts(sol()?"Alice":"Bob");
    }
    return 0;
}