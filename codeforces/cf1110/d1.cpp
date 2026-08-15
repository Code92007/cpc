// //#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
// #include<map>
// #include<set>
// using namespace std;
// #define rep(i,a,b) for(int i=(a);i<=(b);++i)
// #define per(i,a,b) for(int i=(a);i>=(b);--i)
// typedef long long ll;
// typedef double db;
// typedef pair<int,int> P;
// #define fi first
// #define se second
// #define pb push_back
// #define dbg(x) cerr<<(#x)<<":"<<x<<" ";
// #define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
// #define SZ(a) (int)(a.size())
// #define sci(a) scanf("%d",&(a))
// #define scll(a) scanf("%lld",&(a))
// #define pt(a) printf("%d",a);
// #define pte(a) printf("%d\n",a)
// #define ptlle(a) printf("%lld\n",a)
// #define debug(...) fprintf(stderr, __VA_ARGS__)
// const int N=1e3+10;
// int t,n,m,x,y,z,a[N],b[N][N],c[N],in[N],ans[N];
// vector<int>e[N];
// void add(int x,int y){
//     in[y]++;
//     e[x].pb(y);
// }
// bool sol(){
//     bool ok=1;
//     rep(i,1,n){
//         rep(j,i+1,n){
//             if(b[i][j]+b[j][i]==3)return 0;
//             if(c[i]>0 && c[j]>0){
//                 if(b[i][j]==2)return 0;
//             }
//             if(c[i]<0 && c[j]<0){
//                 if(b[i][j]==1)return 0;
//             }
//             if(c[i]>0 && c[j]<0){
//                 if(b[i][j]==2)add(i,j);
//             }
//             if(c[i]<0 && c[j]>0){
//                 if(b[j][i]==2)add(j,i);
//             }
//         }
//     }
//     queue<int>q;
//     rep(i,1,n){
//         if(!in[i]){
//             q.push(i);
//             ans[i]=0;
//         }
//     }
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         for(auto &v:e[u]){
//             if((--in[v])==0){
//                 ans[v]=ans[u]+1;
//                 q.push(v);
//             }
//         }
//     }
//     rep(i,1,n){
//         if(in[i])return 0;
//     }
//     rep(i,1,n){
//         ans[i]*=c[i];
//     }
//     // rep(i,1,n){
//     //     rep(j,1,n){
//     //         if(i==j)continue;
//     //         if(b[i][j]==1 && ans[i]+ans[j]<0)return 0;
//     //         if(b[i][j]==2 && ans[i]+ans[j]>=0)return 0;
//     //     }
//     // }
//     puts("YES");
//     rep(i,1,n){
//         printf("%d ",ans[i]);
//     }
//     puts("");
//     return 1;
// }
// int main(){
//     sci(t);
//     while(t--){
//         sci(n),sci(m);
//         rep(i,1,n){
//             in[i]=0;
//             e[i].clear();
//         }
//         rep(i,1,m){
//             sci(x),sci(y),sci(z);
//             b[x][y]=z;
//         }
//         rep(i,1,n){
//             if(b[i][i]==1)c[i]=1;
//             else c[i]=-1;
//         }
//         if(!sol()){
//             puts("NO");
//         }
//     }
//     return 0;
// }