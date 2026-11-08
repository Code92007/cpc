//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=2e5+10;
int t,n,a[N],b[N],id[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",&b[i]);
            id[i]=i;
        }
        sort(id+1,id+n+1,[&](int x,int y){
            return min(a[x],b[x])<min(a[y],b[y]);
        });
        //g[i][j]表示最后一位有无翻转，总共翻转奇/偶方案是否合法
        vector<vector<int>>g(2,vector<int>(2.0));
        g[0][0]=g[1][1]=1;
        for(int i=2;i<=n;++i){
            vector<vector<int>>f(2,vector<int>(2.0));
            for(int j=0;j<2;++j){
                int px=a[id[i-1]],py=b[id[i-1]];
                if(j&1)swap(px,py);
                for(int k=0;k<2;++k){
                    int cx=a[id[i]],cy=b[id[i]];
                    if(k&1)swap(cx,cy);
                    if(px<cx && py<cy){
                        for(int l=0;l<2;++l){
                            f[k][l^k]|=g[j][l];
                        }
                    }
                }
            }
            g.swap(f);
        }
        bool ans=g[0][0]||g[1][0];
        puts(ans?"YES":"NO");
    }
    return 0;
}