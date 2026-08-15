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
const int N=2e5+10;
int t,n,m,x,y,z,a[N],c[N],deg[N][2],ans[N];
bool vis[N];
vector<P>e[N];
bool sol(){
    queue<int>q;
    rep(i,1,n){
        if(!deg[i][0] || !deg[i][1]){
            vis[i]=1;
            q.push(i);
        }
    }
    int cnt=n;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(deg[x][0]==0)ans[x]=-cnt;
        else ans[x]=cnt;
        cnt--;
        for(auto &[y,o]:e[x]){
            if(vis[y])continue;
            deg[y][o]--;
            if(deg[y][0]==0 || deg[y][1]==0){
                vis[y]=1;
                q.push(y);
            }
        }
    }
    if(cnt>0)return 0;
    puts("YES");
    rep(i,1,n){
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            deg[i][0]=deg[i][1]=0;
            e[i].clear();
            vis[i]=0;
        }
        rep(i,1,m){
            sci(z),sci(x),sci(y);
            z--;
            deg[x][z]++;
            deg[y][z]++;
            e[x].pb(P(y,z));
            e[y].pb(P(x,z));
        }
        if(!sol()){
            puts("NO");
        }
    }
    return 0;
}