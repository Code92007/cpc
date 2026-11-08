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
int t,n,a[105],ans;
int main(){
    sci(t);
    while(t--){
        sci(n);
        int sum=0,sum2=0;
        rep(i,1,n){
            sci(a[i]);
            sum+=1<<a[i];
        }
        sum2=sum/2;
        sort(a+1,a+n+1);
        int tot=0;
        per(i,n,1){
            int w=1<<a[i];
            if(tot+w<=sum2)tot+=w;
        }
        printf("%lld\n",1ll*tot*(sum-tot));
    }
    return 0;
}