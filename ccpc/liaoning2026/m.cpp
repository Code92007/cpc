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
const int N=1e6+10;
char s[10];
int t,n,p[N],sz[N],par[N];
int m;
int main(){
    scanf("%s",s+1);
    if(s[1]=='f'){
        sci(t);
        while(t--){
            sci(n);
            rep(i,1,n)sz[i]=0;
            rep(i,2,n){
                sci(p[i]);
                sz[p[i]]++;
            }
            printf("%d\n",sz[1]);
            int sum=0;
            rep(i,1,sz[1]){
                sum+=sz[i+1]+1;
                printf("%d ",sum);
                //printf("%d ",sz[i+1]+1);
            }
            puts("");
            fflush(stdout);
        }
    }
    else{
        sci(t);
        while(t--){
            n=1;
            sci(m);
            n+=m;
            rep(i,1,m){
                sci(sz[i]);
            }
            sort(sz+1,sz+m+1);
            rep(i,1,m){
                int w=sz[i]-sz[i-1]-1;
                int k=i+1;
                par[k]=1;
                rep(j,1,w){
                    par[++n]=k;
                }
            }
            pte(n);
            rep(i,2,n){
                printf("%d ",par[i]);
            }
            puts("");
            fflush(stdout);
        }
    }
    return 0; 
}