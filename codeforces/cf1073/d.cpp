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
char s[N],w[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        int cnt=0,cnt2=0;
        rep(i,1,n){
            if(s[i]==')'){
                cnt=i;
                break;
            }
        }
        per(i,n,1){
            if(s[i]=='('){
                cnt2=i;
                break;
            }
        }
        int c=0;
        rep(i,1,n){
            if(i==cnt||i==cnt2)continue;
            w[++c]=s[i];
        }
        bool ok=0;
        rep(i,1,c){
            if(s[i]==w[i])continue;
            if(w[i]=='(' && s[i]==')')ok=1;
        }
        if(!ok)puts("-1");
        else printf("%d\n",c);
    }
    return 0;
}