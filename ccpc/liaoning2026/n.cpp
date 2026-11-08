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
typedef pair<__int128,__int128> P;
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
const int N=5e5+10;
const ll mod=1000000000000000003;
int t,n;
ll d,s[N],a[N],b[N];
ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
struct Frac{
    ll num,den;
    Frac(ll n=0,ll d=1){
        if(d<0)n=-n,d=-d;
        ll g=gcd(abs(n),d);
        num=n/g;
        den=d/g;
    }
    Frac operator+(const Frac& o)const{
        return Frac(num*o.den+o.num*den,den*o.den);
    }
    Frac operator-(const Frac& o) const{
        return Frac(num*o.den-o.num*den,den*o.den);
    }
    Frac operator*(const Frac& o)const{
        return Frac(num*o.num,den*o.den);
    }
    Frac operator/(const Frac& o)const{
        return Frac(num*o.den,den*o.num);
    }
    bool operator==(const Frac& o)const{
        return num==o.num && den==o.den;
    }
    bool operator<(const Frac& o)const{
        return num*o.den<o.num*den;
    }
    bool operator>(const Frac& o)const{
        return o<(*this);
    }
};
Frac cal(ll s,ll x){
    Frac now(x,1),nex(x-1,1),S(s,1);
    return now+S/now-(nex+S/nex);
}
void sol(){
    vector<int>p;
    __int128 sum=0;
    ll mn=1e18,mx=0;
    rep(i,1,n){
        ll w=sqrt(s[i]);
        while((w+1)*(w+1)<=s[i])w++;
        b[i]=w;
        //assert(w*w==s[i]);
        if(a[i]<=b[i]){
            ll oth=s[i]/a[i];
            sum+=a[i]+oth;
            sum%=mod;
            continue;
        }
        p.push_back(i);
    }
    if(p.empty()){
        ll ans=sum;
        ptlle(ans);
        return;
    }
    Frac mn(0,1),mx(1e18,1);
    while(true){
        
    }
    // vector<Frac>all;
    // for(auto &i:p){
    //     Frac d1=cal(s[i],a[i]),d2=cal(s[i],b[i]+1);//d1>d2 单减
    //     all.push_back(d1);
    //     all.push_back(d2);
    // }
    // all.push_back(Frac(0,1));
    // all.push_back(Frac(1e18,1));
    // sort(all.begin(),all.end());
    // all.erase(unique(all.begin(),all.end()),all.end());
    // int l=0,r=all.size()-1,ans;
    // while(l<=r){
    //     int mid=(l+r)/2;
    //     Frac now=all[mid];
    // }
    ll a = L.first, b = L.second;
        ll c = R.first, d = R.second;
        // 中位数 M = (a+c)/(b+d)
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&d);
        rep(i,1,n){
            scanf("%lld%lld",&s[i],&a[i]);
        }
        sol();
    }
    return 0; 
}