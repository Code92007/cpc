#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
#define ull unsigned ll
const int N = 1<<19, P = 998244353;
const int Primitive_root = 3;
int n,m,v;
struct Z{
    int x;
    Z(const int _x=0):x(_x){}
    Z operator +(const Z &r)const{ return x+r.x<P?x+r.x:x+r.x-P;}
    Z operator -(const Z &r)const{ return x<r.x?x-r.x+P:x-r.x;}
    Z operator -()const{ return x?P-x:0;}
    Z operator *(const Z &r)const{ return static_cast<ull>(x)*r.x%P;}
    Z operator +=(const Z &r){ return x=x+r.x<P?x+r.x:x+r.x-P, *this;}
    Z operator -=(const Z &r){ return x=x<r.x?x-r.x+P:x-r.x, *this;}
    Z operator *=(const Z &r){ return x=static_cast<ull>(x)*r.x%P, *this;}
    friend Z Pow(Z, int);
    pair<Z,Z> Mul(pair<Z,Z> x, pair<Z,Z> y, Z f)const{
        return make_pair(
            x.first*y.first+x.second*y.second*f,
            x.second*y.first+x.first*y.second
        );
    }
};
Z Pow(Z x, int y=P-2){
    Z ans=1;
    for(; y; y>>=1, x=x*x) if(y&1) ans=ans*x;
    return ans;
}
namespace Poly{
    Z w[N];
    Z Inv[N];
    vector<Z> ans;
    vector<vector<Z> > p;
    ull F[N];
    int Get_root(){
		static int pr[N],cnt;
		int n=P-1,sz=(int)(sqrt(n)),root=-1;
		for(int i=2;i<=sz;++i){if(n%i==0)pr[cnt++]=i;while(n%i==0)n/=i;}
		if(n>1)pr[cnt++]=n;
		for(int i=1;i<P;++i){
			if(Pow((Z)i,P-1).x==1){
				bool fl=true;
				for(int j=0;j<cnt;++j){
					if(Pow(i,(P-1)/pr[j]).x==1){
						fl=false;break;
					}
				}
				if(fl){root=i;break;}
			}
		}
		return root;
	}
    void Init(){
    	//printf("root:%d\n",Primitive_root=Get_root()); 先求出来原根然后当const用 
        for(int i=1; i<N; i<<=1){
            w[i]=1;
            Z t=Pow((Z)Primitive_root, (P-1)/i/2);
            for(int j=1; j<i; ++j) w[i+j]=w[i+j-1]*t;
        }
        Inv[1]=1;
        for(int i=2; i<N; ++i) Inv[i]=Inv[P%i]*(P-P/i);
    }
    int Get(int x){ int n=1; while(n<=x) n<<=1; return n;}
    int Mod(int x){ return x<P?x:x-P;}
    void DFT(vector<Z> &f, int n){
        if((int)f.size()!=n) f.resize(n);
        for(int i=0, j=0; i<n; ++i){
            F[i]=f[j].x;
            for(int k=n>>1; (j^=k)<k; k>>=1);
        }
        if(n<=4){
            for(int i=1; i<n; i<<=1) for(int j=0; j<n; j+=i<<1){
                Z *W=w+i;
                ull *F0=F+j, *F1=F+j+i;
                for(int k=j; k<j+i; ++k, ++W, ++F0, ++F1){
                    ull t=(*F1)*(W->x)%P;
                    (*F1)=*F0+P-t, (*F0)+=t;
                }
            }
        }
        else{
            for(int j=0; j<n; j+=2){
                int t=F[j+1];
                F[j+1]=Mod(F[j]+P-t), F[j]=Mod(F[j]+t);
            }
            for(int j=0; j<n; j+=4){
                int t0=F[j+2], t1=F[j+3]*w[3].x%P;
                F[j+2]=F[j]+P-t0, F[j]+=t0;
                F[j+3]=F[j+1]+P-t1, F[j+1]+=t1;
            }
            for(int i=4; i<n; i<<=1) for(int j=0; j<n; j+=i<<1){
                Z *W=w+i;
                ull *F0=F+j, *F1=F+j+i;
                for(int k=j; k<j+i; k+=4, W+=4, F0+=4, F1+=4){
                    int t0=(W->x)**F1%P;
                    int t1=(W+1)->x**(F1+1)%P;
                    int t2=(W+2)->x**(F1+2)%P;
                    int t3=(W+3)->x**(F1+3)%P;
                    *F1=*F0+P-t0, *F0+=t0;
                    *(F1+1)=*(F0+1)+P-t1, *(F0+1)+=t1;
                    *(F1+2)=*(F0+2)+P-t2, *(F0+2)+=t2;
                    *(F1+3)=*(F0+3)+P-t3, *(F0+3)+=t3;
                }
            }
        }
        for(int i=0; i<n; ++i) f[i]=F[i]%P;
    }
    void IDFT(vector<Z> &f, int n){
        f.resize(n), reverse(f.begin()+1, f.end()), DFT(f, n);
        Z I=1;
        for(int i=1; i<n; i<<=1) I*=(P+1)/2;
        for(int i=0; i<n; ++i) f[i]*=I;
    }
    vector<Z> operator +(const vector<Z> &f, const vector<Z> &g){
        vector<Z> ans=f;
        ans.resize(max(f.size(), g.size()));
        for(int i=0; i<(int)g.size(); ++i) ans[i]+=g[i];
        return ans;
    }
    vector<Z> operator *(const vector<Z> &f, const vector<Z> &g){
        static vector<Z> F, G;
        F=f, G=g;
        int p=Get(f.size()+g.size()-2);
        DFT(F, p), DFT(G, p);
        for(int i=0; i<p; ++i) F[i]*=G[i];
        IDFT(F, p);
        return F.resize(min(m+1,f.size()+g.size()-1)), F;
    }
}
using namespace Poly;
Z fac[N],ifac[N];
void init(int n){
	fac[0]=1;
    for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i;
    } 
	ifac[n]=Pow(fac[n]);
    for(int i=n;i;--i){
    	ifac[i-1]=ifac[i]*i;
    }
}
vector<Z>f,g;
int main(){
    Init();
    init(N-1);
    scanf("%d%d",&n,&m);
    int lg=1;
	while((1<<lg)<=m)lg++;
    //printf("lg:%d\n",lg);
	f.resize(1<<lg);
	g.resize(1<<lg);
    for(int i=1;i<=n;++i){
        scanf("%d",&v);
        if(i==1){
            for(int j=0;j<=v;++j){
                f[j].x=1;
            }
        }
        else{
            for(int j=0;j<=v;++j){
                g[j].x=1;
            } 
            f=f*g;
        }
    }
    printf("%d\n",f[m]);
    return 0;
}