//#include<bits/stdc++.h>
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
typedef pair<int,int> P;
typedef pair<int,int> Complex;
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
const int N=105,C=55,S=2505,mod=998244353;
int a,b,c,m,p[N],las[C][C];
map<P,bool>used;
Complex step[S];
Complex dir[4]={Complex(1,0),Complex(0,1),Complex(-1,0),Complex(0,-1)};
ll e[N];
//(a+bi)*(c+di)
//ac-bd+(bc+ad)i
Complex mul(Complex A,Complex B,int m){  // m是模数
    int a=A.fi,b=A.se,c=B.fi,d=B.se;
    int x=(1ll*a*c%m - 1ll*b*d%m) % m;
    int y=(1ll*b*c%m + 1ll*a*d%m) % m;
    return Complex((x+m)%m, (y+m)%m);
}
Complex modpow(Complex x,ll n,int mod){
    Complex res=Complex(1,0);
    for(;n;n/=2,x=mul(x,x,mod)){
        if(n&1)res=mul(res,x,mod);
    }
    return res;
}
int modpow(int x,ll n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
void add(int &x,int y){
    x=(x+y)%mod;
}
int sol(){
    rep(i,1,m){
        if(p[i]%4==3 && e[i]%2==1)return 0;
    }
    int rx=((-a)%c+c)%c,ry=((-b)%c+c)%c;
    //printf("rx:%d ry:%d\n",rx,ry);
    vector<vector<int> >f(c,vector<int>(c,0));
    rep(k,0,3){//直接初始时，考虑*i的四个方向
        int x=(dir[k].fi%c+c)%c,y=(dir[k].se%c+c)%c;
        add(f[x%c][y%c],1);
    }
    rep(i,1,m){
        vector<vector<int> >g(c,vector<int>(c,0));
        if(p[i]%4==3){
            Complex cur=modpow(Complex(p[i],0),e[i]/2,c);
            rep(u,0,c-1){
                rep(v,0,c-1){
                    Complex w=mul(Complex(u,v),cur,c);
                    add(g[w.fi][w.se],f[u][v]);
                    //printf("u:%d v:%d w:(%d,%d) dp:%d\n",u,v,w.fi,w.se,g[w.fi][w.se]);
                }
            }
        }
        else{
            int x,y;
            if(p[i]==2){
                x=1,y=1;
                Complex cur = modpow(Complex(1,-1), e[i], c);
                rep(u,0,c-1){
                    rep(v,0,c-1){
                        if(!f[u][v]) continue;
                        Complex w = mul(Complex(u,v), cur, c);
                        add(g[w.fi][w.se], f[u][v]);
                    }
                }
            }
            else if(p[i]%4==1){
                rep(j,1,p[i]){
                    rep(z,1,p[i]){
                        if(j*j+z*z==p[i]){
                            x=j;
                            y=z;
                        }
                    }
                }
                //printf("i:%d x:%d y:%d\n",i,x,y);
                if(e[i]<=10000){
                    rep(j,0,e[i]){
                        Complex l=modpow(Complex(x,y),j,c);
                        Complex r=modpow(Complex(x,-y),e[i]-j,c);
                        Complex cur=mul(l,r,c);
                        //printf("k:%d j:%d x:%d y:%d\n",k,j,x,y);
                        rep(u,0,c-1){
                            rep(v,0,c-1){
                                Complex w=mul(Complex(u,v),cur,c);
                                add(g[w.fi][w.se],f[u][v]);
                                //printf("u:%d v:%d w:(%d,%d) dp:%d\n",u,v,w.fi,w.se,g[w.fi][w.se]);
                            }
                        }
                    }
                }
                else{//p字型循环节
                    rep(u,0,c-1){
                        rep(v,0,c-1){
                            las[u][v]=-1;
                        }
                    }
                    rep(j,0,e[i]){
                        Complex l=modpow(Complex(x,y),j,c);
                        Complex r=modpow(Complex(x,-y),e[i]-j,c);
                        Complex cur=mul(l,r,c);
                        int &pre=las[cur.fi][cur.se];
                        if(~pre){
                            int cyc=j-pre;
                            ll val=e[i]-j;
                            step[j]=step[pre];
                            rep(s,pre,j-1){
                                int id=s-pre;
                                rep(u,0,c-1){
                                    rep(v,0,c-1){
                                        Complex w=mul(Complex(u,v),step[s],c);
                                        //ll cnt = (val/cyc) + (id < (val%cyc) ? 1 : 0);  // < 而不是 <=
                                        ll cnt=(val/cyc)+(id<=(val%cyc));
                                        add(g[w.fi][w.se],1ll*cnt%mod*f[u][v]%mod);
                                    }
                                }
                            }
                            break;
                        }
                        else{
                            pre=j;
                            step[j]=cur;
                            rep(u,0,c-1){
                                rep(v,0,c-1){
                                    Complex w=mul(Complex(u,v),cur,c);
                                    add(g[w.fi][w.se],f[u][v]);
                                }
                            }
                        }
                    }
                }
            }
        }
        f.swap(g);
        // rep(u,0,c-1){
        //     rep(v,0,c-1){
        //         printf("i:%d dp[(%d,%d)]:%d\n",i,u,v,f[u][v]);
        //     }
        // }
    }
    return f[rx][ry];
}
int main(){
    sci(a),sci(b),sci(c),sci(m);
    rep(i,1,m){
        scanf("%d%lld",&p[i],&e[i]);
    }
    printf("%d\n",sol());
    return 0;
}