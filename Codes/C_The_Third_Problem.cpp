#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mod = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	map<ll, ll> indx;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		indx[x] = i;
	}
	ll ans = 1;
	int mnx = indx[0], mxx = indx[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (indx[i] >= mnx and indx[i] <= mxx)
		{
			ans = (ans * (mxx - mnx + 1 - i)) % mod;
		}
		else if (indx[i] < mnx) mnx = indx[i];
		else mxx = indx[i];
	}
	cout << ans % mod << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll tc = 1;
	cin >> tc;
	for (ll t = 1; t <= tc; t++)
	{
		solve();
	}
	return 0;
}