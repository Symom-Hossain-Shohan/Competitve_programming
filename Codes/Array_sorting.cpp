#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
	ll n; 
	cin >> n; 
	vector<ll> gcd;
	for (int i = 1; i <= n; i++)
	{
		ll x;
		cin >> x;
		if (abs(i - x) != 0) gcd.push_back(abs(i - x));
	}
	ll g = gcd[0];
	for (int i = 1; i < (int)gcd.size(); i++)
	{
		g = __gcd(g, gcd[i]);
	}
	cout << g << endl;
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