//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=105;
int n;
string s,t;
int main(){
    cin>>n;
    rep(i,1,n){
        int m;
        cin>>s>>m;
        int win=0,lose=0;
        int ans=0;
        rep(j,1,m){
            cin>>t;
            if(t=="W"||t=="RW"){
                if(win>=2)ans+=4;
                else ans+=2;
                if(t[0]=='R')ans++;
                win++;
                lose=0;
            }
            else{
                if(win>=2)ans+=2;
                else if(!lose)ans++;
                win=0;
                lose=1;
            }
        }
        cout<<s<<" "<<ans<<endl;
    }
    return 0;
}