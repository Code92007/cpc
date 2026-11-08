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
const int N=2e5+10;
int t,n,k,a[N],to[N];
int p[N],c;
bool no[N];
//有公因子 但不是完全包含
//互质
int main(){
    for(int i=2;i<N;++i){
        if(!no[i])p[++c]=i;
        for(int j=2*i;j<N;j+=i){
            no[j]=1;
        }
    }
    int las=N;
    per(i,N-1,2){
        if(!no[i])las=i;
        to[i]=las;
    }
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        rep(i,1,n){
            printf("%d ",to[a[i]]);
        }
        puts("");
    }
    return 0;
}
/*
5 
1 1 1 2 3
1 1 1 2 3
*/