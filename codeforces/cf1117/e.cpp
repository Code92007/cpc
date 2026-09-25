//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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
const int N=2e5+10;
int t,n,m,cur[N];
ll all;
struct node{
    ll c,d,pos,id;
};
vector<P>a[N];
vector<node>e[N];
vector<ll>sum[N];
priority_queue<node>q;
set<P>upd;
bool cmp(node a,node b){
    return a.c>b.c;
}
bool operator<(node a,node b){
    return a.d<b.d;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&all);
        rep(i,1,n){
            cur[i]=-1;
            a[i].clear();
            e[i].clear();
            sum[i].clear();
        }
        while(!q.empty())q.pop();
        upd.clear();
        rep(i,1,n){
            sci(m);
            rep(j,0,m-1){
                a[i].pb(P(0,0));
            }
            ll now=0,mx=-1e18;
            rep(j,0,m-1){
                scanf("%lld",&a[i][j].fi);
            }
            rep(j,0,m-1){
                scanf("%lld",&a[i][j].se);
                now+=a[i][j].fi;
                node x;
                x.c=max(mx,now);
                mx=max(mx,now);
                x.d=a[i][j].se-now;
                x.pos=i;
                x.id=j;
                e[i].pb(x);
                now-=a[i][j].se;
                sum[i].pb(now);
            }
            sort(e[i].begin(),e[i].end(),cmp);
            while(!e[i].empty()){
                node y=e[i].back();
                if(y.c<=all){
                    q.push(y);
                    e[i].pop_back();
                }
                else{
                    upd.insert(P(y.c,i));
                    break;
                }
            }
        }
        P ans=P(-1,1);
        while(!q.empty()){
            node x=q.top();
            q.pop();
            int p=x.pos,id=x.id;
            ll c=x.c;
            if(cur[p]>=id){ 
                continue;
            }
            x.d=-(sum[p][id]-(cur[p]<0?0:sum[p][cur[p]]));
            if(id>ans.fi || (id==ans.fi&&p<ans.se)){
                ans=P(id,p);
            }
            if(x.d<0){
                continue;
            }
            ll d=x.d;
            all+=d;
            cur[p]=id;
            while(!upd.empty() && (*upd.begin()).fi<=all){
                P x=*upd.begin();
                upd.erase(x);
                int p=x.se;
                while(!e[p].empty()){
                    node y=e[p].back();
                    ll w=y.c-(cur[p]<0?0:sum[p][cur[p]]);
                    if(w<=all){
                        q.push(y);
                        e[p].pop_back();
                    }
                    else{
                        upd.insert(P(w,p));
                        break;
                    }
                }
            }
        }
        printf("%lld %lld\n",ans.fi+1,ans.se);
    }
    return 0;
}