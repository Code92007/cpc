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
const int N=2e5+10;
int t,n,px,py,qx,qy,a[N];
db dis;
ll sq(ll x){
    return x*x;
}
bool sol(){
    sci(n);
    sci(px),sci(py),sci(qx),sci(qy);
    ll sum=sq(px-qx)+sq(py-qy),sum2=0;
    rep(i,1,n){
        sci(a[i]);
        sum2+=a[i];
    }
    sum2=1ll*sum2*sum2;
    //printf("sum:%lld sum2:%lld\n",sum,sum2);
    if(sum2<sum)return 0;
    sort(a+1,a+n+1);
    ll now=a[n];
    per(i,n-1,1)now-=a[i];
    if(now<=0)return 1;
    now=1ll*now*now;
    if(now>sum)return 0;
    return 1;
}
int main(){
    sci(t);
    while(t--){
        puts(sol()?"Yes":"No");
    }
    return 0;
}

/*
9=01001
15=01111
25=11001

两个数
1&1 1^1
1 0
1&0 1^0
0 1
0&0 0^0 只能都是0
三个数
1&1&1 1^1^1 √
1&1&0 1^1^0 √ 
0&0&0

n奇数 全为l
n偶数 
0110
1000

110
111

n为偶
特判n=2 无解
如果l和r的最高位一样 肯定不行 -1
如果不一样 让n-2个是l 2个是和l没有交集的

n为奇 全一样
*/
