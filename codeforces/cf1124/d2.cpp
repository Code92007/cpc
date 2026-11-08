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
int t,n,q,a[N],p,x;
vector<int>b={0,3,5,6,9,10,12,15};
map<int,bool>in;
int main(){
    for(auto &v:b){
        in[v]=true;
    }
    sci(t);
    while(t--){
        sci(n);sci(q);
        int cnt=0;
        rep(i,1,n){
            sci(a[i]);
            if(in.count(a[i]))cnt++;
        }
        printf("%d",cnt);            
        while(q--){
            sci(p);sci(x);
            cnt-=in.count(a[p]);
            a[p]=x;
            cnt+=in.count(a[p]);
            printf(" %d",cnt);
        }
        puts("");
    }
    return 0;
}