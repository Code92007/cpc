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
const int N=2e5+10;
int t,n,q,x,cnt[2];
//int cnt01,cnt10;
char s[N];
ll cal(ll i){
    return 1ll*i*(n-i);
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(q);
        scanf("%s",s+1);
        ll ans=0;
        cnt[0]=cnt[1]=0;
        rep(i,1,n)cnt[s[i]-'0']++;
        rep(i,1,n-1){
            if(s[i]^s[i+1])ans+=cal(i);
        }
        ans+=1ll*cnt[0]*cnt[1];
        printf("%lld",ans/2);
        while(q--){
            sci(x);
            if(x>1 && (s[x]^s[x-1]))ans-=cal(x-1);
            if(x<n && (s[x]^s[x+1]))ans-=cal(x);
            ans-=1ll*cnt[0]*cnt[1];
            cnt[s[x]-'0']--;
            s[x]^='0'^'1';
            cnt[s[x]-'0']++;
            ans+=1ll*cnt[0]*cnt[1];
            if(x>1 && (s[x]^s[x-1]))ans+=cal(x-1);
            if(x<n && (s[x]^s[x+1]))ans+=cal(x);
            printf(" %lld",ans/2);
        }
        puts("");
        //cnt01=cnt10=0;
        // rep(i,1,n-1){
        //     if(s[i]=='0' && s[i+1]=='1')cnt01++;
        //     if(s[i]=='1' && s[i+1]=='0')cnt10++;
        // }
        // printf("%d\n",min(cnt01,cnt10));
        // while(q--){
        //     sci(x);
        //     if(x>1){
        //         if(s[x-1]=='0' && s[x]=='1')cnt01--;
        //         if(s[x-1]=='1' && s[x]=='0')cnt10--;
        //     }
        //     if(x<n){
        //         if(s[x]=='0' && s[x+1]=='1')cnt01--;
        //         if(s[x]=='1' && s[x+1]=='0')cnt10--;
        //     }
        //     s[x]^='0'^'1';
        //     if(x>1){
        //         if(s[x-1]=='0' && s[x]=='1')cnt01++;
        //         if(s[x-1]=='1' && s[x]=='0')cnt10++;
        //     }
        //     if(x<n){
        //         if(s[x]=='0' && s[x+1]=='1')cnt01++;
        //         if(s[x]=='1' && s[x+1]=='0')cnt10++;
        //     }
        // }
        // printf("%d\n",min(cnt01,cnt10));
    }
    return 0;
}