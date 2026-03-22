x#include<bits/stdc++.h>
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
const int N=2e5+10;
int t,n,a[N],b[N];
char s[N];
vector<int>ans;
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        rep(i,1,n){
            if(s[i]=='1')a[i]=1;
            else a[i]=0;
            b[i]=a[i];
        }
        sort(a+1,a+n+1);
        ans.clear();
        rep(i,1,n){
            if(a[i]!=b[i]){
                ans.pb(i);
            }
        }
        if(!SZ(ans))puts("Bob");
        else{
            puts("Alice");
            pte(SZ(ans));
            for(auto &v:ans){
                printf("%d ",v);
            }
            puts("");
        }
    }
    return 0;
}