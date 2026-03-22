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
const int N=2e5+10;
int t,n;
char s[N];
bool used[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        rep(i,1,n){
            used[i]=0;
        }
        int ans=0;
        rep(i,1,n){
            if(s[i]=='1'){
                if(i-1>=1)used[i-1]=1;
                if(i+1<=n)used[i+1]=1;
                used[i]=1;
                ans++;
            }
        }
        int cnt=0;
        rep(i,1,n){
            if(used[i] || s[i]=='1'){
                ans+=(cnt+2)/3;
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        ans+=(cnt+2)/3;
        pte(ans);
    }
    return 0;
}