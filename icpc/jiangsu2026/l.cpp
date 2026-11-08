//#include<bits/stdc++.h>
#include<iostream>
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
const int N=5e5+10;
int t,n,a[N];
/*
完整思路：
1. 考虑第一个样例1 2 3，先手可以操作1之后变成0 1 1，所以如果有1且有n是奇数一定是先手赢
2. 否则先手看看能不能只操作最小的数然后赢，比如3 4 6，先手仍然可以操作3变成2 3 3然后先手赢，这个本质是先手操作完之后把游戏规则取min那步废掉了，那只有减1的游戏就只用看剩余局面的数sum的奇偶性
Q：为什么操作最小值之后的游戏只关心 sum，继续操作最小值对全局和的影响也不是 -1？
A：如果操作后面的位置，相当于这个游戏没有取min(aj,ai)的规则；如果想带上取min，相当于只能操作第一个数，那就看第一个数的奇偶性；
事实上，sum为偶数，因为操作完第一个数之后序列形如x x+1 x+1 x+1 x+1 x+1，那如果x是奇数，后面的全是偶数，sum是不可能为偶数的，所以x一定是偶数
那么如果后手还操作第一个数的话，先手只需模仿仍然操作第一个数即可
换言之，此时游戏分裂成两个子游戏选项，玩第一个数，或者玩后面的数，那么后手玩第一个先手就跟着玩第一个
后手玩后面的只-1先手也跟着玩后面的，这样能始终控制sum在先手操作完之后是偶数
3. 在这个思路下，给序列sort，从小到大找，看看能不能找到一个数使得操作这个数操作完之后序列的sum是偶数，从而先手必胜，如果有多个满足的话先手只要操作最小的那个就赢了
实际上只用写3，1、2都会包含在3里
*/
int main(){
    sci(t);
    while(t--){
        sci(n);
        int one=0,even=0,mn=1e9;
        ll sum=0;
        rep(i,1,n){
            sci(a[i]);
            if(a[i]==1)one++;
            sum+=a[i];
            mn=min(mn,a[i]);
        }
        if(one>0 && n%2==1)puts("Insight");
        else if((1ll*mn*n)%2)puts("Insight");
        else{
            sort(a+1,a+n+1);
            bool ok=0;
            ll sum2=0;
            rep(i,1,n){
                sum-=a[i];
                sum2+=a[i];
                ll tmp=sum2+1ll*(n-i)*a[i]-1;
                if(tmp%2==0){
                    ok=1;
                    break;
                }
            }
            puts(ok?"Insight":"Maya");
        }
    }
    return 0;
}
/*
3
3
2 1 3
4
2 1 3 1
4
2 1 1 4
3
1 1 2 2
3 3 3
2 2 2

3 6 7 8
2 3 3 3
1 2 2 2
0 1 1 1 
先3 6 6 7
后3 5 6 6
先3 4 5 5
*/