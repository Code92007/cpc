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
const int N=105;
int n,m,a[N][N],b[N][N],cnt;
char x;
/*
每次只能改一个前缀矩形 加任意值
问最后加成目标矩形需要最少几次
其中B是一个值，W是另一个值，具体是几无所谓
但是这两种要能区分
从右下角贪心即可
*/
void chg(int x,int y,int z){
    rep(i,1,x){
        rep(j,1,y){
            b[i][j]+=z;
        }
    }
}
int main(){
    cin>>n>>m;
    rep(i,1,n){
        rep(j,1,m){
            cin>>x;
            if(x=='B')a[i][j]=1000;
            else a[i][j]=100000;
        }
    }
    per(i,n,1){
        per(j,m,1){
            if(a[i][j]!=b[i][j]){
                int v=a[i][j]-b[i][j];
                chg(i,j,v);
                cnt++;
            }
        }
    }
    pte(cnt);
    return 0;
}
