//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
using ll = long long;

ll floor_sum(ll a, ll b, ll c, ll n) {
    if (n < 0) return 0;
    if (a < 0) {
        ll a2 = -a, b2 = -b;
        return -floor_sum(a2, b2 - c + 1, c, n);
    }
    if (b < 0) {
        ll k = (-b + c - 1) / c;
        return floor_sum(a, b + k * c, c, n) - k * (n + 1);
    }
    if (a >= c || b >= c) {
        return floor_sum(a % c, b % c, c, n) + n * (n + 1) / 2 * (a / c) + (n + 1) * (b / c);
    }
    ll m = (a * n + b) / c;
    return n * m - floor_sum(c, c - b - 1, a, m - 1);
}

void solve() {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    ll L = min(N, M);
    ll p = floor_sum(A, B, M, L - 1) - floor_sum(A - 1, B - 1, M, L - 1);
    ll ans = L - p;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}