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
const int N=2e5+10,M=32;
int n,m,l[N],r[N],v[N],ans[N];
int add[M][N],no[M][N];
vector<int>can[M];
bool sol(){
    rep(i,1,m){
        int len=r[i]-l[i]+1;
        per(j,30,0){
            int x=v[i]>>j&1;
            if(x){
                if(no[j][r[i]]-no[j][l[i]-1]==len)return 0;
                ans[*lower_bound(can[j].begin(),can[j].end(),l[i])]|=1<<j;
            }
        }
    }
    rep(i,1,n){
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 1;
}
int main(){
    sci(n),sci(m);
    rep(i,1,m){
        sci(l[i]),sci(r[i]),sci(v[i]);
        per(j,30,0){
            int x=v[i]>>j&1;
            if(!x){
                add[j][l[i]]++;
                add[j][r[i]+1]--;
            }
        }
    }
    rep(i,0,30){
        int now=0;
        rep(j,1,n){
            now+=add[i][j];
            if(now>0)no[i][j]=1;
            else can[i].pb(j);
            no[i][j]+=no[i][j-1];
        }
    }
    if(!sol()){
        puts("-1");
    }
    return 0;
}