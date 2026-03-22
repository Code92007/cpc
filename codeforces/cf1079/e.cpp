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
const int N=35;
int t,n,cnt,m;
vector<int>e[N];
vector<int>now;
vector<vector<int>>step;
bool ok[N][N];
map<vector<int>,int>pos;
map<int,vector<int>>mp;
vector<int> ask(int k){
    if(mp.count(k))return mp[k];
    cnt++;
    printf("? %d\n",k);
    fflush(stdout);
    int q,v;
    vector<int>ans;
    scanf("%d",&q);
    rep(i,1,q){
        scanf("%d",&v);
        ans.pb(v);
    }
    return ans;
}
void dfs(int u){
    now.pb(u);
    step.pb(now);
    rep(i,1,n){
        if(ok[u][i])dfs(i);
    }
    //sort(e[u].begin(),e[u].end());
    // for(auto &v:e[u]){
    //     dfs(v);
    // }
    now.pop_back();
}
void gen(){
    step.clear();
    rep(i,1,n){
        now.clear();
        dfs(i);
    }
    //printf("SZ(step):%d\n",SZ(step));
    int c=0;
    for(auto &v:step){
        pos[v]=++c;
        // for(auto &x:v)printf("%d->",x);
        // puts("");
    }
}
void brush(vector<int>&p,int &m){
    int las=-1;
    bool can=0;
    for(auto &v:p){
        if(~las){
            if(!ok[las][v]){
                e[las].pb(v);
                ok[las][v]=1;
                can=1;
                m++;
            }
        }
        las=v;
    }
    //if(can)gen();
}
// void out(){
//     printf("SZ(step):%d\n",SZ(step));
//     int c=0;
//     for(auto &v:step){
//         printf("[%d]",++c);
//         for(auto &x:v){
//             printf("->%d",x);
//         }
//         puts("");
//     }
// }
void output(int m){
    printf("! %d\n",m);
    rep(i,1,n){
        for(auto &v:e[i]){
            printf("%d %d\n",i,v);
        }
    }
    fflush(stdout);
}
int main(){
    sci(t);
    while(t--){
        mp.clear();
        pos.clear();
        m=0;
        sci(n);
        rep(i,1,n){
            rep(j,1,n){
                ok[i][j]=0;
            }
            e[i].clear();
        }
        int l=1,r=1<<30;
        while(l<=r){//1-r
            int mid=(l+r)/2;
            if(!SZ(ask(mid)))r=mid-1;
            else l=mid+1;
        }
        int ub=r;
        for(int i=1;i<=ub;){
            int l=i,r=ub;
            vector<int>L=ask(l);
            while(l<=r){
                int mid=(l+r)/2;
                vector<int>p=ask(mid);
                if(p[0]!=L[0])r=mid-1;
                else l=mid+1;
            }
            //[i,r]
            int R=r,x=i+1;
            while(x<=R){
                vector<int>p=ask(x);
                brush(p,m);
                l=x;r=R;
                while(l<=r){
                    int mid=(l+r)/2;
                    vector<int>q=ask(mid);
                    if(q[1]!=p[1])r=mid-1;
                    else l=mid+1;
                }
                x=l;
            }
            i=R+1;
        }
        output(m);
    }
    return 0;
}