//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--)
	{
		vector<int> a(3); for(auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		cout << min(a[2] - a[0], a[1]) << '\n'; 
	}
	return 0;
} 