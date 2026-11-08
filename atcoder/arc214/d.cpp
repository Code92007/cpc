#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n,a[N][N],c[N][N];
int main(){
    scanf("%d",&n);
    c[0][0]=1;
    for(int i=1;i<N;++i){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<=i;++j){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            a[i+1][j]=a[i][j+1]+c[i-1+j-1][j-1];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%d%c",a[i][j]," \n"[j==n]);
        }
    }
    return 0;
}
