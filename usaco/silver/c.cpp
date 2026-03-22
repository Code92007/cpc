#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
#define ull unsigned long long
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
int t,n,k;
char s[N];
vector<int>pos[N];
int main(){
    sci(t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        if(k==1){
            int cnt=0;
            rep(i,0,n-1){
                if(s[i]=='1')cnt++;
            }
            printf("%d %d\n",cnt,cnt);
            continue;
        }
        // if(k==n){
        //     int w=s[0]-'0';
        //     if(w)
        // }
        rep(j,0,k-1){
            pos[j].clear();
            pos[j].pb(1);
        }
        rep(i,0,n-k-1){
            int p=i%k,w=pos[p].back();
            if(s[i]==s[i+1]){
                pos[p].pb(w);
            }
            else{
                pos[p].pb(w^1);
            }
        }
        int mn=0,mx=0,pre=0,diff=n,diff2=n,seg=s[0]-'0';
        rep(i,0,k-1){
            int all=SZ(pos[i]),one=0,zero=0,now=1;
            //printf("i:%d all:%d\n",i,all);
            for(auto &v:pos[i]){
                if(v==1)one++;
                else zero++;
            }
            if(one>zero)swap(one,zero),now=0;
            diff=min(diff,zero-one);
            pre^=now;
            mn+=one;
        }
        //printf("mn:%d pre:%d seg:%d\n",mn,pre,seg);
        if(pre!=seg)mn+=diff;
        pre=0;
        rep(i,0,k-1){
            int all=SZ(pos[i]),one=0,zero=0,now=1;
            for(auto &v:pos[i]){
                if(v==1)one++;
                else zero++;
            }
            if(one<zero)swap(one,zero),now=0;
            diff2=min(diff2,one-zero);
            pre^=now;
            mx+=one;
        }
        if(pre!=seg)mx-=diff2;
        printf("%d %d\n",mn,mx);
    }
    return 0;
}