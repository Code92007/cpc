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
const int N=105;
int t,n;
char s[N];
int main() {
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        int cnt1=0,cnt2=0,cnt3=1;
        rep(i,2,n){
            if(s[i]==s[1])cnt1++;
            if(s[i]==s[i-1])cnt2++;
            else cnt3++;
        }
        if(cnt1==n-1)pte(1);
        else if(cnt2>0){
            pte(cnt3+1-(s[1]==s[n]));
        }
        else{
            pte(cnt3);
        }
    }
    return 0;
}