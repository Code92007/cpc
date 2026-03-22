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
int t,n,a[N],ans[N];
//2^z>=logy/logx
//(x^a)>=(y^b)
//2^alogx>=2^blogy
//2^-z<=logx/logy
ll sol(){
    ll res=0;
    rep(i,2,n){
        if(a[i]<a[i-1] || ans[i-1]>0){
            if(a[i]==1)return -1;
            double x=log(a[i-1])/log(a[i]);
            if(x>=1){
                rep(z,0,20){
                    int w=1<<z;
                    if(w>=x){
                        ans[i]=ans[i-1]+z;
                        break;
                    }
                }
            }
            else{
                double y=log(a[i])/log(a[i-1]);
                per(z,20,0){
                    int w=1<<z;
                    if(w<=y){
                        ans[i]=max(0,ans[i-1]-z);
                        break;
                    }
                }
            }
        }
        //printf("i:%d ans:%d\n",i,ans[i]);
        res+=ans[i];
    }
    return res;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
            ans[i]=0;
        }
        printf("%lld\n",sol());
    }
    return 0;
}