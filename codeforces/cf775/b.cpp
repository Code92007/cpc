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
const int N=1e6+10;
int t,n,c,v;
int sum[N];
bool ok[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(c);
        rep(i,1,c)sum[i]=ok[i]=0;
        rep(i,1,n){
            sci(v);
            sum[v]=1;
            ok[v]=1;
        }
        rep(i,1,c){
            sum[i]=sum[i-1]+sum[i];
        }
        bool yes=1;
        for(int i=1;i<=c;++i){
            if(!ok[i])continue;
            for(int j=i;j<=c;j+=i){
                int l=j-1,r=min(c,j+i-1);
                //printf("l:%d r:%d\n",l,r);
                if(sum[r]-sum[l]>0){
                    int v=j/i;
                    if(!ok[v])yes=0;
                }
            }
        }
        puts(yes?"Yes":"No");
    }
    return 0;
}