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
using namespace std;
const int N=5e6+10,M=35;
bitset<M>vis[N];
int m,n,x,y,sg[N],now[N];
int cnt[N];
ll ans;
void init(){
    int up=5e6;
    int tot=0;
    for(int i=1;i<=up;++i){
        rep(j,0,400){
            if(!vis[i].test(j)){
                sg[i]=j;
                tot++;
                break;
            }
        }
        for(int j=2*i;j<=up;j+=i){
            cnt[j]++;
            vis[j].set(sg[i]);
            tot++;
        }
    }
    //int res=0;
    //rep(i,1,up)res=max(res,sg[i]);
    //pte(res);
    //printf("tot:%d\n",tot);
}
int main(){
    init();
    scanf("%d%d%d%d",&m,&n,&x,&y);
    rep(i,m-x,m){
        now[sg[i]]++;
        //printf("i:%d sg:%d\n",i,sg[i]);
    }
    rep(j,n-y,n){
        ans+=now[sg[j]];
        //printf("j:%d sg:%d\n",j,sg[j]);
    }
    printf("%lld\n",1ll*(x+1)*(y+1)-ans);
    return 0;
}