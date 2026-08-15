//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
const int N=1<<18;
double PI=acos(-1.0);
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[N],A[N],B[N];
int R[N];
void FFT(C a[],int n){
	for (int i=0;i<n;i++)
		if (i<R[i])
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void FFT_times(vector <ll> &a,vector <ll> &b,vector <ll> &c){
	int n,d;
	for (int i=0;i<a.size();i++)
		A[i]=C(a[i],0);
	for (int i=0;i<b.size();i++)
		B[i]=C(b[i],0);
	for (n=1,d=0;n<a.size()+b.size()-1;n<<=1,d++);
	for (int i=0;i<n;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(2*PI*i/n),sin(2*PI*i/n));
	}
	for (int i=a.size();i<n;i++)
		A[i]=C(0,0);
	for (int i=b.size();i<n;i++)
		B[i]=C(0,0);
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	c.clear();
	for (int i=0;i<=a.size()+b.size()-2;i++)
		c.push_back(((LL)(A[i].r/n+0.5)));
}
int n;
ll res[N];
char s[N];
vector<ll>l,r,ans;
void op(int x){
    int cnt=0;
    rep(i,0,n-1){
        int w=s[i]-'a';
        cnt+=(w==x);
    }
    l.clear();r.clear();
    l.push_back(cnt);
    rep(i,0,n-2){
        int w=s[i]-'a';
        cnt-=(w==x);
        l.push_back(cnt);
    }
    per(i,n-1,0){
        int w=s[i]-'a';
        if(w==x)r.push_back(1);
        else r.push_back(0);
    }
    FFT_times(l,r,ans);
    rep(i,0,n-1){
        res[i]+=ans[n-1-i];
    }
}
int main(){
    sci(n);
    scanf("%s",s);
    rep(i,0,25){
        op(i);
    }
    rep(i,0,n-1){
        printf("%lld\n",res[i]);
    }
	return 0;
}