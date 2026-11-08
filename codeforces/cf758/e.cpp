#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,p[2][N],c[N],b[4],id[2][N],ans;
void Swap(){
    for(int i=1;i<=n;++i){
        swap(p[0][i],p[1][i]);
    }
}
void Flip(){
    for(int i=1;i<=n;++i){
        p[0][i]=-p[0][i];
    }
}
bool ok(int m){
    for(int i=0;i<2;++i){
        if(i&1)Swap();
        for(int j=0;j<2;++j){
            if(j&1)Flip();
            auto f=[&](int x,int y){
                if(x==0 && j==1)y=n+1-y;
                x^=i;
                return id[x][y];
            };
            for(int k=1;k<=3;++k){
                b[k]=k;
            }
            do{
                for(int l=0;l<2;++l){
                    if(j==1 && l==0)continue;
                    int cnt=0,mx=1e9;
                    for(int x=1;x<=n;++x){
                        int v=f(0,x);
                        if(c[v]==b[1]){
                            cnt++;
                            mx=p[0][v];
                            if(cnt==m)break;
                        }
                    }
                    int cnt2=0,mx2=1e9;
                    for(int x=1;x<=n;++x){
                        int v=f(l,x);
                        if(c[v]==b[2]){
                            if(p[0][v]<=mx)continue;
                            cnt2++;
                            mx2=p[l][v];
                            if(cnt2==m)break;
                        }
                    }
                    if(cnt2<m)continue;
                    int cnt3=0;
                    for(int x=1;x<=n;++x){
                        int v=f(l,x);
                        if(c[v]==b[3]){
                            if(p[0][v]<=mx || p[l][v]<=mx2)continue;
                            cnt3++;
                            if(cnt3==m)break;
                        }
                    }
                    if(cnt3>=m){
                        if(j&1)Flip();
                        if(i&1)Swap();
                        return 1;
                    }
                }
            }while(next_permutation(b+1,b+4));
            if(j&1)Flip();
        }
        if(i&1)Swap();
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&p[0][i],&p[1][i],&c[i]);
        id[0][i]=id[1][i]=i;
    }
    for(int k=0;k<2;++k){
        sort(id[k]+1,id[k]+n+1,[&](int x,int y){
            return p[k][x]<p[k][y];
        });
    }
    int l=1,r=n/3;
    while(l<=r){
        int mid=(l+r)/2;
        if(ok(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",3*ans);
    return 0;
}