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
int t,n,m,cnt[N];
vector<int>e[N];
bool ok[N][N];
vector<int> ask(int k){
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
void brush(vector<int>&p,int &m,int &z){
    int las=-1;
    vector<int>tmp;
    for(auto &v:p){
        if(~las){
            if(!ok[las][v]){
                e[las].pb(v);
                z=v;
                for(auto &x:tmp){
                    cnt[x]+=cnt[v];
                }
                ok[las][v]=1;
                m++;
            }
        }
        las=v;
        tmp.pb(v);
    }
}
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
        m=0;
        sci(n);
        rep(i,1,n){
            cnt[i]=1;
            rep(j,1,n){
                ok[i][j]=0;
            }
            e[i].clear();
        }
        int x=2,z=1;//z是最后一个可被复用的点
        while(true){
            vector<int>p=ask(x);
            if(!SZ(p))break;
            if(SZ(p)==1)z=p[0];
            else brush(p,m,z);
            x+=cnt[z];
        }
        output(m);
    }
    return 0;
}
/*
1->2->3 1->3 3+3=6
1
1 2
1 2 3
1 3
2
2 3
3

2->1->3 3+2=5
1
1 3
2
2 1
2 1 3
3
*/