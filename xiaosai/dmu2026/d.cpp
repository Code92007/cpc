#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef array<ll,3> A;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define scl(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=200010;
const ld eps=1e-9;
int t,n,X,Y,R,r;
ll ans,now;
struct node{
    int x,y;
}a[N];
ll cal(node x,node y,node z){
    return abs((ll)(y.y-x.y)*(z.x-x.x)+(ll)(x.y-z.y)*(y.x-x.x));
}
bool check2(node s1,node s2,node l1,node l2){
    ll t1=(ll)(l2.y-l1.y)*(s1.x-l1.x)-(ll)(l2.x-l1.x)*(s1.y-l1.y);
    ll t2=(ll)(l2.y-l1.y)*(s2.x-l1.x)-(ll)(l2.x-l1.x)*(s2.y-l1.y);
    return (t1>=0&&t2<=0)||(t1<=0&&t2>=0);
}
bool check(node x,node y,node z){
    ll fz=x.y-z.y;
    ll fm=-(x.x-z.x);
    ll fc=-fm*x.y-fz*x.x;
    __int128 dd=(__int128)fz*X+(__int128)fm*Y+fc;
    __int128 rr=R;
    if(dd*dd<rr*rr*((__int128)fz*fz+(__int128)fm*fm)) return false;
    if(check2(y,z,x,{X,Y})) return false;
    return true;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(X),sci(Y),sci(R);
        ans=now=0;
        r=1;
        rep(i,1,n){
            sci(a[i].x),sci(a[i].y);
            a[i+n]=a[i];
        }
        rep(i,1,n){
            while(r<2*n){
                if(r<=i)r++;
                else if(check(a[i],a[r],a[r+1])){
                    now+=cal(a[i],a[r],a[r+1]);
                    r++;
                }
                else break;
            }
            ans=max(ans,now);
            now-=cal(a[i],a[i+1],a[r]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}