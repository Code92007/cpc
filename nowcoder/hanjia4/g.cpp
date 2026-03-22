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
int mx,v;
int f(int x){
    if(!x)return 0;
    int res=1;
    for(;x;x/=10){
        res=res*(x%10);
        if(!res)return 0;
    }
    return res;
}
int main(){
    rep(i,1,1000000000){
        int j=i,cnt=0;
        while(j!=f(j)){
            j=f(j);
            cnt++;
        }
        if(cnt>mx)mx=cnt,v=j;
        if(mx==cnt)printf("i:%d g:%d\n",i,cnt);
    }
    printf("mx:%d v:%d\n",mx,v);
    return 0;
}