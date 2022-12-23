#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
	ll n;
	cin >> n;
	ll cnt = 0;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				cnt++;
				swap(v[j], v[j + 1]);
			}
		}
	}
	cout << v[0] ;
	for (int i = 1; i < (int)v.size(); i++) cout << ' ' << v[i];
	cout << endl << cnt << endl;
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