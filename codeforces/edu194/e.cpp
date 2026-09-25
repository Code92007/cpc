#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,q,l,r,b[N],a[2][2][N];
char s[N];
int f(int l,int r,int x,int y){
    return a[x][y][r]-a[x][y][l]+(b[r]==x && b[l]==y);
}
int main(){
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i){
        b[i]=s[i]-'0';
    }
    for(int k=2;k<=n;++k){
        for(int i=0;i<=1;++i){
            for(int j=0;j<=1;++j){
                a[i][j][k]=a[i][j][k-1];
            }
        }
        a[b[k-1]][b[k]][k]++;
    }
    while(q--){
        scanf("%d%d",&l,&r);
        int c01=f(l,r,0,1),c00=f(l,r,0,0),c11=f(l,r,1,1);
        int w=max({c01,(c01+c00+1)/2,(c01+c11+1)/2,(c01+c00+c11+2)/3});
        printf("%d\n",4*w-(r-l+1));
    }
    return 0;
}