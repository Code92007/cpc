#include<bits/stdc++.h>
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
int t,n,m,a[N],b[N];
multiset<int>q;
bool dfs(int x){
    if(q.count(x)){
        q.erase(q.find(x));
        return 1;
    }
    if(!x)return 0;
    int v=x/2;
    return dfs(v) && dfs(x-v);
}
bool sol(){
    if(n<m)return 0;
    rep(i,1,n){
        q.insert(a[i]);
    }
    per(i,m,1){
        if(!dfs(b[i]))return 0;
    }
    if(SZ(q))return 0;
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);
        q.clear();
        rep(i,1,n)sci(a[i]);
        rep(i,1,m)sci(b[i]);
        printf("%s\n",sol()?"Yes":"No");
    }
    return 0;
}
/*

3 4 5
5 4 3

*/