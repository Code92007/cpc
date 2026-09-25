// Problem: E. Cyclic Balance
// Contest: Codeforces - Educational Codeforces Round 194 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2260/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int maxn = 300100;

int n, m, a[maxn][2], b[maxn];
char s[maxn];

void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 1; ++j) {
			a[i][j] = a[i - 1][j];
		}
		++a[i][s[i] - '0'];
	}
	for (int i = 2; i <= n; ++i) {
		b[i] = b[i - 1] + (s[i - 1] != s[i]);
	}
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (r - l + 1 <= 2) {
			printf("%d\n", 4 - (r - l + 1));
			continue;
		}
		int c0 = a[r][0] - a[l - 1][0], c1 = a[r][1] - a[l - 1][1];
		int t = b[r] - b[l] + (s[l] != s[r]);
		auto check = [&](int x) -> bool {
			if (t > x / 2 || x < r - l + 1) {
				return 0;
			}
			if (max(c0, c1) > x / 2) {
				return 0;
			}
			return t + (x - (r - l + 1)) * 2 >= x / 2;
		};
		int L = 1, R = n * 10, ans = -1;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (check(mid * 4)) {
				ans = mid;
				R = mid - 1;
			} else {
				L = mid + 1;
			}
		}
		printf("%d\n", ans * 4 - (r - l + 1));
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
