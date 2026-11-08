#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=505;
int n,c,a[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            a[i][j]=++c;
            a[j][i]=a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%d%c",a[i][j]," \n"[j==n]);
        }
    }
    return 0;
}