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
const int N=1e5+10;
int n;
deque<int>q;
int main(){
    sci(n);
    if(n<=3)puts("-1");
    else if(n==4){
        puts("2 4 1 3");
    }
    else{
        q.pb(n-1);
        q.pb(n-4);
        q.pb(n-2);
        q.pb(n);
        q.pb(n-3);
        rep(i,5,n-1){
            if(i&1)q.pb(n-i);
            else q.push_front(n-i);
        }
        for(auto &v:q){
            printf("%d ",v);
        }
    }
    return 0;
}