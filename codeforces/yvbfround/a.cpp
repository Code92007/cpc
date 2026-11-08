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
const int N=1e3+10;
int t,n;
char s[N];
void sol(){
    n=strlen(s+1);
    if(n==1){
        if(s[1]=='9'){
            puts("10");
            return;
        }
        s[1]++;
        printf("%s\n",s+1);
        return;
    }
    bool all9=(s[1]=='9' && s[2]=='9');
    int sg=(s[2]<s[1])?1:(s[2]>s[1]?-1:0),p=0;
    if(sg==0){
        if(all9){
            rep(i,1,n+1){
                if(i&1)putchar('1');
                else putchar('0');
            }
            puts("");
            return;
        }
        s[2]++;
        rep(i,3,n){
            if(i&1)s[i]='0';
            else s[i]='1';
        }
        printf("%s\n",s+1);
        return;
    }
    rep(i,3,n){
        if(s[i]==s[i-1]){
            if(s[i]=='9'){
                s[i-2]++;
            }
        }
    }
}
int main(){
    sci(t);
    while(t--){
        scanf("%s",s+1);
        sol();
    }
    return 0;
}