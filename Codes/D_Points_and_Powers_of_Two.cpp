#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	sort(v.begin(), v.end());
	//when answer is 3
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 1; j <= 2e9; j *= 2)
		{
			if (binary_search(v.begin(), v.end(), v[i] - j) and binary_search(v.begin(), v.end(), v[i] + j))
			{
				cout << 3 << endl;
				//cout << j << endl;
				cout << v[i] - j << ' ' << v[i] << ' ' << v[i] + j << endl;
				return;
			}
		}
	}
	//when answer is 2
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 1; j <= 2e9; j *= 2)
		{
			if (binary_search(v.begin(), v.end(), v[i] - j))
			{
				cout << 2 << endl;
				cout << v[i] << ' ' << v[i] - j << endl;
				return;
			}
			else if (binary_search(v.begin(), v.end(), v[i] + j))
			{
				cout << 2 << endl;
				cout << v[i] << ' ' << v[i] + j << endl;
				return;
			}
		}
	}
	cout << 1 << endl;
	cout << v[0] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll tc = 1;
	//cin >> tc;
	for (ll t = 1; t <= tc; t++)
	{
		solve();
	}
	return 0;
}