//#include<bits/stdc++.h>
#include<iostream>
#include<map>
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
const int N=3e5+10;
int t,n,nex[N][10];
char s[N];
ll sum[N],sum2[N];
void add(int l,int r){
    sum[r]++;
    int len=r-l+1;
    sum[l-1]-=len+1;
    if(l-2>=0)sum[l-2]+=len;
}
void add2(int l,int r,int w){
    sum2[l]+=w,sum2[r+1]-=w;
}
int main(){
    sci(t);
    while(t--){
        rep(i,1,n)sum[i]=sum2[i]=0;
        sci(n);
        scanf("%s",s+1);
        rep(i,0,9)nex[n+1][i]=n+1;
        per(i,n,1){
            rep(j,0,9)nex[i][j]=nex[i+1][j];
            nex[i][s[i]-'0']=i;
        }
        rep(l,1,n){
            int p=l;
            p=nex[p][2];
            p=nex[p][0];
            p=nex[p][2];
            if(p==n+1 || nex[p][5]>n || nex[p][6]<nex[p][5]){
                add(l,n);
            }
            else{//5<6
                int x=nex[p][5],y=nex[p][6];
                add(l,x-1),add(y,n);
                int cnt=n-y+1;
                add2(l,y-1,cnt);
            }
        }
        per(i,n-1,1)sum[i]+=sum[i+1];
        per(i,n-1,1)sum[i]+=sum[i+1];
        rep(i,1,n)sum2[i]+=sum2[i-1];
        rep(i,1,n){
            printf("%lld%c",sum[i]+sum2[i]," \n"[i==n]);
        }
    }
    return 0;
}
//1 2 3 4 0 0
//1 1 1 1 -4 0
//1 0 0 0 -5 4