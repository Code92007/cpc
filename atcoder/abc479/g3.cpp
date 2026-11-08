#include<bits/stdc++.h>
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
int n;
ll a[N],b[N];
ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
bool upd(P &x,P y){
    if((__int128)x.fi*y.se>(__int128)y.fi*x.se){
        x=y;
        return 1;
    }
    return 0;
}
P cal(){
    vector<int>id;
    rep(i,1,n){
        if(a[i]) id.pb(i); // 收集所有 A_i != 0 的点，坚决不删！
    }
    if(!SZ(id)) return P(1e18, 1); // 全是 A_i=0，交给 k=0/∞ 处理

    sort(id.begin(), id.end(), [&](int x, int y){
        return (long double)b[x] / a[x] < (long double)b[y] / a[y];
    });

    ll tot = 0, now = 0;
    for(auto &v : id) tot += llabs(a[v]);

    int w = -1;
    for(auto &v : id){
        now += llabs(a[v]);
        if(2ll * now >= tot){
            w = v; break;
        }
    }

    if(w == -1) return P(1e18, 1);

    // 关键：如果算出的中位数斜率不在 [0,1] 内，说明区间最优解在边界，直接交给外层 k=0/1 处理
    if (b[w] * a[w] < 0 || llabs(b[w]) > llabs(a[w])) {
        return P(1e18, 1);
    }

    // 计算距离 p/q，这里 q 一定是 llabs(a[w])（因为中位数在 [0,1] 内，|b[w]| <= |a[w]|）
    ll p = 0, q = llabs(a[w]);
    P tmp = P(b[w], a[w]);
    rep(i, 1, n){
        ll z = 1ll * b[i] * tmp.se - 1ll * tmp.fi * a[i];
        if(z < 0) z = -z;
        p += z;
    }
    ll g = gcd(p, q);
    return P(p/g, q/g);
}
int main(){
    sci(n);
    rep(i,1,n)scanf("%lld",&a[i]);
    rep(i,1,n)scanf("%lld",&b[i]);
    P ans=cal();
    ll sa=0,sb=0,s1=0,s2=0;
    rep(i,1,n){
        sa+=llabs(a[i]);
        sb+=llabs(b[i]);
        s1+=llabs(b[i]-a[i]);
        s2+=llabs(b[i]+a[i]); 
    }
    upd(ans,P(s1,1)); // k=1
    upd(ans,P(s2,1)); // k=-1
    upd(ans,P(sa,1)); // k=∞
    upd(ans,P(sb,1)); // k=0
    rep(i,1,n)b[i]=-b[i];
    upd(ans,cal());
    rep(i,1,n)swap(a[i],b[i]);
    upd(ans,cal());
    rep(i,1,n)b[i]=-b[i];
    upd(ans,cal());
    if(ans.fi==0)ans.se=1;
    printf("%lld %lld\n",ans.fi,ans.se);
    return 0;
}