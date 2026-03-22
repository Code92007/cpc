//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef unsigned long long ull;
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
const int N=55;
int n;
ull a[N],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%llu",&a[i]);
    }
    for(int j=31;j>=0;--j){//枚举是在哪位首次出现不卡上界的数（自由元）的，类似数位dp
        //f[i][0/1][0/1]表示考虑前i个数时，当前位的异或和为0/1，当前是否已选自由元的方案数
        //如果没有第三维，则考虑枚举最后一个自由元的位置
        vector<vector<ull>>f(2,vector<ull>(2,0));
        f[0][0]=1;
        int cnt=0;
        for(int i=1;i<=n;++i){
            int w=a[i]>>j&1;
            cnt+=w;
            ull freechoose=1ll<<j;//如果这位不卡上界，则低位可随便选，[0,2^j-1]，有2^j种选法
            ull lowval=((1ll<<j)-1)&a[i];//如果这位卡上界，则低位可选[0,lowval]，有lowval+1种选法
            vector<vector<ull>>g(2,vector<ull>(2,0));
            for(int x=0;x<=1;++x){
                for(int y=0;y<=1;++y){
                    if(w==0){//只能卡上界
                        g[x][y]+=f[x][y]*(lowval+1);//取0，卡上界
                    }
                    else{
                        if(y==0){
                            g[x][1]+=f[x][y];//取0，不卡上界，出现自由元，低位的异或要和其他位的异或和一致
                            g[x^1][y]+=f[x][y]*(lowval+1);//取1，之前卡上界
                        }
                        else{
                            g[x][y]+=f[x][y]*freechoose;//取0，不卡上界，但是因为不是首个，所以随便选
                            g[x^1][y]+=f[x][y]*(lowval+1);//取1，之前不卡上界，本次卡上界，取[0,lowval]
                        }
                    }
                }
            }
            f.swap(g);
        }
        // rep(x,0,1){
        //     rep(y,0,1){
        //         printf("j:%d x:%d y:%d f:%llu\n",j,x,y,f[x][y]);
        //     }
        // }
        ans+=f[0][1];
        if(j==0)ans+=f[0][0];
        if(cnt&1){
            break;
        }
    }
    printf("%llu\n",ans-1);
    return 0;
}