//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
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
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=1e5+10,M=3e5+10;
struct edge{
    int x,y,z;
}e[M];
int t,n,m,s;
ll a[N];
queue<int>q;
vector<edge>x;
P mx[N];
bool in[N];
vector<P>f[N];
bool ok(int x){
    return (x<s && a[x]>a[s]) || (x>s && a[x]>=a[s]);
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(s);
        rep(i,1,n){
            sci(a[i]);
            in[i]=0;
            f[i].clear();
        }
        rep(i,1,m){
            sci(e[i].x),sci(e[i].y),sci(e[i].z);
        }
        sort(e+1,e+m+1,[&](edge a,edge b){
            if(a.x!=b.x)return a.x<b.x;
            if(a.y!=b.y)return a.y<b.y;
            return a.z>b.z;
        });
        x.clear();
        mx=P(0,0);
        rep(i,1,m){
            if(x.empty()){
                x.push_back(e[i]);
                continue;
            }
            if(x.back().x==e[i].x && x.back().y==e[i].y){
                continue;
            }
            x.push_back(e[i]);
        }
        for(auto &v:x){
            f[v.x].push_back(P(v.y,v.z));
            if(v.x==s){
                a[v.y]+=v.z;
            }
        }
        rep(i,1,n){
            if(i==s)continue;
            if(ok(i)){
                in[i]=1;
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(auto &x:f[u]){
                int v=x.fi,w=x.se;
                if(v!=s)a[v]+=w;
                if(ok(v) && !in[v]){
                    in[v]=1;
                    q.push(v);
                }
            }
        }
        puts(cnt==n-1?"YES":"NO");
    }
	return 0;
}