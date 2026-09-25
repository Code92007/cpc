//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=55;
int t;
ll x,y,k;
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld%lld",&x,&y,&k);
        ll d=y-x,ans=0;
        int i=0,cur=x;
        while(i<k && cur<=d){
            ans+=d%cur;
            i++,cur++;
        }
        ll rem=k-i;
        ans+=1ll*rem*d;
        printf("%lld\n",ans);
    }
    return 0;
}