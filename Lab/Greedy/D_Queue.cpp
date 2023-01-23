#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	sort(v.begin(), v.end());
	ll ans = 0, t = 0 ;
	for (int i = 0; i < n; i++)
	{
		if (t <= v[i]) ans++, t+=v[i];
		//t += v[i];
	}
	cout << ans << endl;
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