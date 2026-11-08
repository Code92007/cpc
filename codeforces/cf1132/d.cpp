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
const int N=1e3+10;
int t,n,m,u,v,col[N];
char s[N],w[10];
bool vis[N];
vector<int>e[N];
bool dfs(int u,int c){
    vis[u]=1;
    col[u]=c;
    for(auto &v:e[u]){
        if(vis[v]){
            if(col[v]!=-c)return 0;
        }
        else{
            if(!dfs(v,-c))return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%s",w);
    if(w[0]=='f'){
        sci(t);
        while(t--){
            sci(n);
            scanf("%s",s+2);
            int cnt=0;
            rep(i,2,n){
                if(s[i]=='1')cnt++;
            }
            if(cnt==n-1){
                m=n*(n-1)/2;
                printf("%d\n",m);
                rep(i,1,n){
                    rep(j,i+1,n){
                        printf("%d %d\n",i,j);
                    }
                }
                fflush(stdout);
            }
            else{
                vector<int>l,r;
                l.pb(1);
                rep(i,2,n){
                    if(s[i]=='1')l.pb(i);
                    else r.pb(i);
                }
                m=SZ(l)*SZ(r);
                printf("%d\n",m);
                for(auto &x:l){
                    for(auto &y:r){
                        printf("%d %d\n",x,y);
                    }
                }
                fflush(stdout);
            }
        }
    }
    else{
        sci(t);
        while(t--){
            sci(n),sci(m);
            rep(i,1,n){
                e[i].clear();
                vis[i]=col[i]=0;
            }
            rep(i,1,m){
                sci(u),sci(v);
                e[u].pb(v);
                e[v].pb(u);
            }
            if(!dfs(1,1)){
                rep(i,2,n){
                    s[i]='1';
                }
                s[n+1]='\0';
                printf("%s\n",s+2);
            }
            else{
                rep(i,2,n){
                    if(col[i]==col[1])s[i]='1';
                    else s[i]='0';
                }
                s[n+1]='\0';
                printf("%s\n",s+2);
            }
        }
    }
    return 0;
}