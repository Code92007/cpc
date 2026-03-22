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

typedef tuple<int,int,int,int,int,int> A6;
vector<A6> tris;

void add(int x1,int y1,int x2,int y2,int x3,int y3) {
    tris.emplace_back(x1+1, y1+1, x2+1, y2+1, x3+1, y3+1);
}

// x占据了0、1、2 y占据了0、1 称作3x2 下同
void place_3x2(int x, int y) {
    add(x, y, x, y+1, x+1, y);
    add(x+1, y+1, x+2, y, x+2, y+1);
}

void place_2x3(int x, int y) {
    add(x,   y,   x,   y+1, x+1, y);      
    add(x+1, y+1, x+1, y+2, x,   y+2);    
}

void place_6x5(int x, int y) {
    place_3x2(x, y);
    place_3x2(x+3, y);
    place_2x3(x, y+2);
    place_2x3(x+2, y+2);
    place_2x3(x+4, y+2);
}

void place_9x5(int x, int y) {
    add(x,   y,   x,   y+1, x+1, y);      // a
    add(x,   y+2, x,   y+3, x+1, y+1);    // b
    add(x,   y+4, x+1, y+2, x+1, y+3);    // c
    add(x+1, y+4, x+2, y+3, x+2, y+4);    // d
    add(x+2, y,   x+2, y+1, x+3, y);      // e
    add(x+2, y+2, x+3, y+1, x+3, y+2);    // f
    add(x+3, y+3, x+3, y+4, x+4, y+4);    // g
    add(x+4, y,   x+4, y+1, x+5, y+1);    // h
    add(x+4, y+2, x+5, y+2, x+5, y+3);    // i
    add(x+4, y+3, x+5, y+4, x+6, y+4);    // j
    add(x+5, y,   x+6, y,   x+6, y+1);    // k
    add(x+6, y+2, x+7, y+3, x+8, y+3);    // l
    add(x+6, y+3, x+7, y+4, x+8, y+4);    // m
    add(x+7, y,   x+8, y,   x+8, y+1);    // n
    add(x+7, y+1, x+7, y+2, x+8, y+2);    // o
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        tris.clear();
        int N = 3 * n;

        if (n % 2 == 0) {
            for (int i = 0; i < N; i += 3)
                for (int j = 0; j < N; j += 2)
                    place_3x2(i, j);
        } else {
            if (n == 1) {
                add(0, 0, 0, 1, 1, 0);
                add(1, 2, 2, 1, 2, 2);
            }
            else {
                // 1. 上面这块用2x3
                for(int i = 0; i < N; i += 3) {
                    for (int j = 5; j < N; j += 2) {
                        place_3x2(i, j);
                    }
                }
                // 2. 右边这块用5*6
                for (int i = 9; i < N; i += 6)
                    place_6x5(i, 0);

                // 3. 左下角
                place_9x5(0, 0);
            }
        }

        cout << tris.size() << "\n";
        for (auto [x1,y1,x2,y2,x3,y3] : tris)
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
    }
    return 0;
}