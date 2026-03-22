#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
const int N=1e5+10,M=3*N;
int t,k,n,ans[M],res;
char s[M];
void op(int i,int len){
    for(int j=0;j<3;++j){
        int p=i+j;
        for(int k=0;k<3;++k){
            int p2=i+len+k;
            if(s[p]==s[p2]){
                vector<int>l,r;
                for(int x=0;x<3;++x){
                    if(x==j)continue;
                    l.pb(x);
                }
                for(int x=0;x<3;++x){
                    if(x==k)continue;
                    r.pb(x);
                }
                int L=i+l[0],R=i+len+r[0];
                if(s[L]==s[R]){
                    ans[p]=ans[p2]=1;
                    return;
                }
            }
        }
    }
}
void out(){
    int m=3*n;
    printf("%d\n",res);
    rep(i,1,m){
        printf("%d%c",ans[i]," \n"[i==m]);
    }
}
int main(){
    sci(t);sci(k);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        if(n&1){
            puts("-1");
            continue;
        }
        int m=3*n,l=m/2;
        bool same=1;
        for(int j=1;j<=l;++j){
            if(s[j]!=s[j+l]){
                same=false;
                break;
            }
        }
        if(same){
            res=1;
            rep(i,1,m)ans[i]=1;
            out();
            continue;
        }
        rep(i,1,m)ans[i]=2;
        for(int i=1;i<=l;i+=3){
            bool ok=1;
            for(int j=0;j<3;++j){
                int p=i+j;
                if(s[p]!=s[p+l]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                for(int j=0;j<3;++j){
                    int p=i+j;
                    ans[p]=ans[p+l]=1;
                }
                continue;
            }
            op(i,l);
        }
        res=2;
        out();
    }
    return 0;
}