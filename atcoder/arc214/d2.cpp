//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;

typedef long long ll;

int n, a[14][14], c[25][25];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 25; i++) c[i][0] = 1;
	for (int i = 1; i < 25; i++) {
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i + 1][j] = a[i][j + 1] + c[n * 2 - i - j - 2][n - i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", a[i][j]); puts("");
	}
}
