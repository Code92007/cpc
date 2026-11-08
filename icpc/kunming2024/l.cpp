//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=5e5+10;
int t,n,m,a[N],b[N];
bool sol(){
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(a[i]>=1+(i>1))a[i]--,cnt++;
    }
    sort(a+1,a+n+1);
    int x=1,y=1;
    for(int i=0;i<n+m;++i){
        if(x<=n){
            if(a[x]<=i){
                x++;
                continue;
            }
        }
        if(y<=m){
            if(b[y]-cnt<=i){
                cnt-=max(0,b[y]-i);
                y++;
                if(y>m)return 1;
                else continue;
            }
        }
        return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&b[i]);
        }
        puts(sol()?"Yes":"No");
    }
    return 0;
}
/*
3
3 2
1 1 4
2 6
3 2
1 1 4
2 7
2 1
100 100
2
*/