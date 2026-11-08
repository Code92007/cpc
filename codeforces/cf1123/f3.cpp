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
const int N=1e5+10,M=5e7+10;
int t,n,q,a[N],b[M],x;
vector<int>res;
//trans=两两异或取最小的m个
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        rep(i,1,n){
            sci(a[i]);
        }
        sort(a+1,a+n+1);
        res.clear();
        res.pb(a[n]-a[1]);
        while(true){
            bool ok=1;
            int c=0;
            rep(d,0,30){
                c=0;
                rep(i,1,n){
                    rep(j,i+1,n){
                        if((a[i]^a[j])>=(1<<d))break;
                        b[++c]=a[i]^a[j];
                        if(d==0 && c>=n)break;
                    }
                    if(d==0 && c>=n)break;
                }
                if(c>=n)break;
            }
            sort(b+1,b+c+1);
            //printf("k:%d\n",k);
            rep(i,1,n){
                ok&=(a[i]==b[i]);
                //printf("%d ",b[i]);
                a[i]=b[i];
            }
            //puts("");
            res.pb(a[n]-a[1]);
            if(ok)break;
        }
        while(q--){
            sci(x);
            x=min(x,SZ(res)-1);
            printf("%d\n",res[x]);
        }
    }
    return 0;
}