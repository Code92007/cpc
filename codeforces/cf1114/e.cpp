//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10;
int t,n;
ll a[N],b[N],sum,mn;
multiset<ll>l,r;
int main(){
    sci(t);
    while(t--){
        sci(n);
        sum=0;
        mn=1e9;
        rep(i,1,n){
            scanf("%lld",&b[i]);
            mn=min(mn,b[i]);
            sum+=b[i];
        }
        if(sum<=0){
            puts("-1");
            continue;
        }
        if(mn>0){
            sort(b+1,b+n+1);
            rep(i,1,n){
                a[i]=a[i-1]+b[i];
            }
        }
        else{
            l.clear();
            r.clear();
            rep(i,1,n){
                if(b[i]>0)l.insert(b[i]);
                else r.insert(-b[i]);
            }
            rep(i,1,n){
                if(i==1 || r.empty()){
                    int v=*l.begin();
                    l.erase(l.find(v));
                    a[i]=a[i-1]+v;
                    continue;
                }
                if(l.empty()){
                    int v=*r.rbegin();
                    r.erase(r.find(v));
                    a[i]=a[i-1]-v;
                    continue;
                }
                auto it=r.lower_bound(a[i-1]);
                if(it!=r.begin()){
                    it--;
                    int v=*it;
                    //printf("i:%d v1:%d\n",i,v);
                    r.erase(r.find(v));
                    a[i]=a[i-1]-v;
                }
                else{
                    int v=*l.begin();
                    //printf("i:%d v2:%d\n",i,v);
                    l.erase(l.find(v));
                    a[i]=a[i-1]+v;
                }
            }
        }
        rep(i,1,n){
            printf("%lld%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}