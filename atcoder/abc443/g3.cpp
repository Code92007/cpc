//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
typedef unsigned long long ull;
using namespace std;
// sum x=0..n-1 floor((ax+b)/c)
ull f(ull a,ull b,ull c,ull n){
    ull ret=0;
    ret+=b/c*n;b%=c;
    ret+=a/c*n*(n-1)/2;a%=c;
    if(a*n+b<c)return ret;
    return ret+f(c,(a*n+b)%c,a,(a*n+b)/c);
}
//p=f(A,B,M,L−1)−f(A−1,B,M,L−1)
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        ull a,b,m,n,l,ans=0;
        scanf("%llu%llu%llu%llu",&n,&m,&a,&b);
        if(a==0){
            ans=min(n,b);
        }
        else{
            l=min(n,m);
            ans=f(a,b,m,l-1)-f(a-1,b-1,m,l-1);
            ans=l-ans;
            //n=(n-b)/a+1;
            // for(ull lo=1;lo<=b+a*n;lo=lo+lo){
            //     ans+=f(a,b,lo,n)-f(a,b,lo+lo,n)*2;
            // }
        }
        printf("%llu\n",ans);
    }
}