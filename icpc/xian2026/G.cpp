#include <bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;
void solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1; cin>>t;
    while(t--) solve();
    cout.flush(); return 0;
}
void solve() {
    int n,N; cin>>n; vector<ll> a(N=(1<<n));
    for(ll &c:a) cin>>c;
    vector<ll> f(N<<1,0),g(N<<1,0),m(N<<1,0);
    for(int i=0;i<N;++i) f[N+i]=m[N+i]=a[i];
    for(int i=N-1;i;--i) {
        m[i]=min(m[i<<1],m[i<<1|1]);
        g[i]=max({f[i<<1]-m[i],f[i<<1|1]-m[i],g[i<<1]+g[i<<1|1]});
        f[i]=max({f[i<<1],f[i<<1|1],g[i<<1]+g[i<<1|1]});
    }
    cout<<f[1]<<"\n";
}