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
const int N=2e5+10,M=20;
int t,n,a[N],lg[N];
bool used[N];
int main(){
    rep(i,2,N-5)lg[i]=lg[i>>1]+1;
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            used[i]=0;
        }
        int v=n&(-n);
        if(n&1){
            a[n]=n;a[n-1]=n-1;
            a[n-2]=3;a[n-3]=1;
            used[1]=used[3]=used[n-1]=used[n]=1;
        }
        else{
            if(n==6){
                a[3]=4;a[4]=6;a[5]=5;a[6]=3;
                used[3]=used[4]=used[5]=used[6]=1;
            }
            else{
                int x=(1<<lg[n]);
                a[n]=x;a[n-1]=x-1;a[n-2]=x-2;
                a[n-3]=3;a[n-4]=1;
                used[1]=used[3]=used[x-1]=used[x-2]=used[x]=1;
            }
        }
        int c=0;
        rep(i,1,n){
            if(used[i])continue;
            a[++c]=i;
        }
        int now=0;
        rep(i,1,n){
            if(i&1)now&=a[i];
            else now|=a[i];
        }
        printf("%d\n",now);
        rep(i,1,n){
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}
//1 3 2 1 2 3
/*
0 & p1 | p2 & p3 | p4 & p5 | p6 & p7
n为奇数
2、3、5、7
4、5、7
6、7
0 & p1 | p2 & p3 | p4 & p5 | p6 
n为偶数
2、3、5
4、5
6
*/