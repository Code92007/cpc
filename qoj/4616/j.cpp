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
typedef array<ll,3> A;
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
int t,n,a[N],b[N];//>n
map<int,int>q,q2;
priority_queue<int>p;
bool sol(){
    q.clear();
    q2.clear();
    while(!p.empty())p.pop();
    rep(i,1,n){
        q[a[i]]++;
    }
    rep(i,1,n){
        p.push(b[i]);
    }
    int cnt=n;
    while(!p.empty()){
        int x=p.top();
        if(x>cnt){
            if(!q[x])return 0;
            p.pop();
            q[x]--;
            cnt--;
        }
        else{
            break;
        }
    }
    if(!cnt)return 1;
    //开始用mex的个数up+原始固定不动的数cnt2，不能超过剩余总数cnt
    //开始用mex的个数这个只会减少up
    while(!p.empty()){
        int x=p.top();
        //printf("x:%d\n",x);
        p.pop();
        q2[x]++;
    }
    vector<pair<int,int>> v;
    for(auto it:q2){
        int x=it.first,w=it.second;
        v.push_back({x-w,x});
    }
    sort(v.begin(),v.end());
    int up=0;
    for(auto it:v){
        int need=it.first,x=it.second;
        int w=q2[x];
        if(need<=up){
            up+=w;
        }
        else if(q[x]<w){
            return 0;
        }
    }
    return 1;
}
/*
3
5   
0 0 0 0 0
1 2 3 4 5
4
0 1 2 3
0 1 3 3
4
0 3 3 3
2 3 3 3
*/
//0122 2333 012xx=33333
//4  2 0 0
//4  2 0 0
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)sci(a[i]);
        rep(i,1,n)sci(b[i]);
        puts(sol()?"YES":"NO");
    }
    return 0;
}
/*
0122
2333
只要最终保留3个3，那么别的可以是<3的任意值
012
223
*/
/*
4
3
1 2 3
2 2 3
3
0 0 0
2 3 3
3
3 3 2
2 3 3
4
10000 10000 10000 10000
2 3 3 3
*/