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
const int N=2e5+10;
int n,t;
ll a[N],b[N],sum;
int tmp,ans;
priority_queue<ll,vector<ll>,greater<ll> >in;
priority_queue<ll>out;
int main(){
    sci(n),sci(t);
    rep(i,1,n)scanf("%lld",&a[i]);
    rep(i,1,n)scanf("%lld",&b[i]);
    rep(i,1,n){
        t-=a[i];
        if(t<=0)break;
        in.push(b[i]);
        while(!out.empty() && sum>t){
            ll v=out.top();
            out.pop();
            sum-=v;
            tmp--;
        }
        while(!in.empty() && sum+in.top()<=t){
            ll v=in.top();
            in.pop();
            sum+=v;
            out.push(v);
            tmp++;
            ans=max(ans,tmp);
        }
        while(!in.empty() && !out.empty()){
            ll v1=in.top(),v2=out.top();
            if(v1>=v2)break;
            in.pop(),out.pop();
            sum-=v2;
            sum+=v1;
            out.push(v1);
        }
        while(!in.empty() && sum+in.top()<=t){
            ll v=in.top();
            in.pop();
            sum+=v;
            out.push(v);
            tmp++;
            ans=max(ans,tmp);
        }
    }
    pte(ans);
    return 0; 
}