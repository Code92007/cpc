//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

struct P { int y, p, q; };

void addRange(vector<int>& s, int a, int b, int step) {
    if (step > 0) for (int x = a; x <= b; x += step) s.push_back(x);
    else for (int x = a; x >= b; x += step) s.push_back(x);
}

vector<P> perfect(int N) {
    int M = N - 1;
    vector<int> s;
    if (M == 0) return {};

    if (M % 4 == 0) {
        int x = M, h = M / 2;
        addRange(s, x-4, h, -2); s.push_back(x-2); addRange(s, h-3, 1, -2); s.push_back(x-1);
        addRange(s, 1, h-3, 2); addRange(s, h, x-4, 2); s.push_back(x);
        addRange(s, x-3, h+1, -2); s.push_back(x-2); addRange(s, h-2, 2, -2); s.push_back(h-1); s.push_back(x-1);
        addRange(s, 2, h-2, 2); addRange(s, h+1, x-3, 2); s.push_back(h-1); s.push_back(x);
    } else {
        int x = M + 1, h = x / 2;
        addRange(s, x-4, h, -2); s.push_back(x-2); addRange(s, h-3, 1, -2); s.push_back(x-1);
        addRange(s, 1, h-3, 2); addRange(s, h, x-4, 2); s.push_back(h-1);
        addRange(s, x-3, h+1, -2); s.push_back(x-2); addRange(s, h-2, 2, -2); s.push_back(h-1); s.push_back(x-1);
        addRange(s, 2, h-2, 2); addRange(s, h+1, x-3, 2);
    }

    vector<int> first(M + 1, 0);
    vector<P> res;
    for (int i = 1; i <= (int)s.size(); i++) {
        int v = s[i-1];
        if (!first[v]) first[v] = i;
        else res.push_back({v + 1, first[v], i});
    }
    return res;
}

vector<P> hooked(int N) {
    vector<P> res;
    auto add = [&](int y, int p, int q) { res.push_back({y, p, q}); };

    if (N == 2) { add(2,1,3); return res; }
    if (N == 3) { add(2,1,3); add(3,2,5); return res; }
    if (N == 6) {
        add(4,1,5); add(5,2,7); add(6,3,9); add(2,4,6); add(3,8,11);
        return res;
    }
    if (N == 7) {
        add(3,3,6); add(4,4,8); add(5,5,10); add(6,1,7); add(7,2,9); add(2,11,13);
        return res;
    }

    if (N % 4 == 2) {
        int r = (N - 2) / 4;
        for (int j = 0; j <= r-3; j++) add(4+2*j, 2*r-j-2, 2*r+4+j-2);
        for (int j = 0; j <= r-1; j++) add(2*r+1+2*j, r+2-j-2, 3*r+3+j-2);
        for (int j = 0; j <= r-2; j++) {
            add(3+2*j, 6*r+1-j-2, 6*r+4+j-2);
            add(2*r+2+2*j, 5*r+2-j-2, 7*r+4+j-2);
        }
        add(2*r, 2*r+3-2, 4*r+3-2);
        add(4*r+1, 3*r+2-2, 7*r+3-2);
        add(4*r+2, 2*r+1-2, 6*r+3-2);
        add(4*r, 2*r+2-2, 6*r+2-2);
    } else {
        int r = (N - 3) / 4;
        for (int j = 0; j <= r-2; j++) {
            add(4+2*j, 2*r+2-j-2, 2*r+6+j-2);
            add(2*r+3+2*j, r+2-j-2, 3*r+5+j-2);
        }
        add(4*r+1, 1, 4*r+2);
        add(2*r+1, 2*r+2, 4*r+3);
        add(4*r+2, r+1, 5*r+3);
        add(4*r, 2*r+3, 6*r+3);
        add(4*r+3, 2*r+1, 6*r+4);
        for (int j = 0; j <= r-2; j++) {
            add(3+2*j, 6*r+2-j, 6*r+5+j);
            add(2*r+2+2*j, 5*r+2-j, 7*r+4+j);
        }
    }

    add(2, 2*N-3, 2*N-1);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<array<int,3>> ans;
    vector<P> pairs;

    if (N % 4 == 0 || N % 4 == 1) {
        ans.push_back({3*N - 1, 0, 1});
        pairs = perfect(N);
    } else {
        ans.push_back({3*N - 2, 0, 1});
        pairs = hooked(N);
    }

    for (auto [y, p, q] : pairs) {
        ans.push_back({N + q, y, N + p});
    }

    for (auto [x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}
