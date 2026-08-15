//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<random>
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
const int up=1<<29;
mt19937_64 mrand(chrono::steady_clock().now().time_since_epoch().count());
int t,x,o,m0,m1,r;
void out(int b){
    printf("%d\n",b);
    fflush(stdout);
}
void out2(int m0,int m1){
    printf("%d %d\n",m0,m1);
    fflush(stdout);
}
int lowbit(int x){
    return x&(-x);
}
int main(){
    sci(t);
    while(t--){
        out(1);
        scanf("%d",&o);
        //o=1 1是v的子集且操作是and v是奇数
        //o=1 1是v的超集且操作是or  v=0或1
        if(o==1){
            m0=0,m1=(mrand()%up)*2+1;//m1是奇数
            out2(m0,m1);
            scanf("%d",&r);
            //①v=0 回答的是等于0或等于rand()
            //②v是奇数 回答的是奇数（不等于rand）或者rand()^奇数（得到偶数） 其中只有rand()=v会区分不出来和①的区别 概率1/(2^29)
            if(r==m0)out(0);
            else if(r==m1)out(1);
            else if(r%2==1)out(0);
            else out(1);
        }
        else if(o%2==0){//x是偶数 &操作
            m0=0,m1=1;
            out2(m0,m1);
            scanf("%d",&r);
            if(r%2==0)out(0);
            else out(1);
        }
        else{//o>1 是奇数 |操作 一定或上了一位新的
            m0=0,m1=lowbit(o^1);
            out2(m0,m1);
            scanf("%d",&r);
            if(r&m1)out(0);
            else out(1);
        }
    }
    return 0;
}