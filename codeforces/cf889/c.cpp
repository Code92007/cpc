#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=1e9+7,inv2=(mod+1)/2;
int n,m,a[N],f[N][N],ans;//f[i][j]表示i和位于右侧的j粘在一起时i期望操作的步数，终态是希望n个数都粘一起
//f[i][j]=1/2(f[i+1][j]+1)+1/2*f[i][j+1]
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    a[n+1]=m+1;
    for(int i=m;i>=1;--i){
        for(int j=m+1;j>i;--j){
            if(j==m+1)f[i][j]=f[i+1][j]+1;//j已经被终点粘住了，只能i往右走
            else f[i][j]=(1ll*inv2*(f[i+1][j]+1)%mod+1ll*inv2*f[i][j+1]%mod)%mod;
        }
    }
    for(int i=1;i<=n;++i){
        ans=(ans+f[a[i]][a[i+1]])%mod;
    }
    printf("%d\n",ans);
    return 0;
}