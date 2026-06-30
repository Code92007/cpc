#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
typedef array<ll,3> A;
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
int t,n;
priority_queue<int,vector<int>,greater<int>>q;
vector<int>a;
int main(){
    sci(t);
    while(t--){
        sci(n);
        if(n==2 || n==3 || n==5)puts("No");
        else if(n==1){
            puts("Yes\n1");
        }
        else{
            a.clear();
            if(n%3==0)a={2,2,2,3,3,6},n-=6;
            else if(n%3==1)a={2,2,2,2},n-=4;
            else if(n%3==2)a={2,2,3,3,6,3,3,6},n-=8;
            for(auto &v:a)q.push(v);
            while(n){
                int v=q.top();
                q.pop();
                v*=2;
                rep(i,1,4)q.push(v);
                n-=3;
            }
            puts("Yes");
            while(!q.empty()){
                int v=q.top();
                q.pop();
                printf("%d",v);
                if(q.empty())puts("");
                else putchar(' ');
            }
        }
    }
    return 0;
}