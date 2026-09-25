#include<bits/stdc++.h>
using namespace std;
int n,m;
int f(int x,int y){
    if(x==1)return 1;
    if(x==2)return vector<int>{3,4}[y-1];
    return x==y?x-2:2;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
       for(int j=1;j<=m;++j){
            printf("%d%c",f(n,i)*f(m,j)," \n"[j==m]);
        }
    }
    return 0;
}