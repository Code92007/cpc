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
const int N=2e5+10;
int t,n,a[2];
char s[N];
int main() {
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        a[0]=a[1]=0;
        rep(i,1,n){
            int v=s[i]-'0';
            a[v]++;
        }
        if(a[0]%2==1){
            pte(a[0]);
            rep(i,1,n){
                if(s[i]=='0')printf("%d ",i);
            }
            puts("");
        }
        else if(a[1]%2==0){
            pte(a[1]);
            if(a[1]){
                rep(i,1,n){
                    if(s[i]=='1')printf("%d ",i);
                }
                puts("");
            }
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
/*
n=4
flip 1 2
2 3 4
1 3 4
翻两个数
flip 1 2 3
2 3 4
1 3 4
1 2 4
翻一个4

flip2 3
1 3
1 2

1000
0有奇数个 ok
1有偶数个 ok
否则不ok
*/