#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void multiply(vector<int> *v, int &sz, int m)
{
	ll cary = 0;
	for (int i = 0; i < sz ; i++)
	{
		ll product = v->at(i) * m + cary;
		v->at(i) = product % 10;
		cary = product / 10;
	}
	while (cary)
	{
		v->at(sz) = cary % 10;
		cary /= 10;
		sz++;
	}
}

void solve()
{
	ll n;
	cin >> n;
	vector<int> v(10000);
	v[0] = 1;
	int sz = 1;
	//factorial
	for (int i = 1; i <= n; i++)
	{
		multiply( &v, sz, i);
	}
	for (int i = sz - 1; i >= 0; i--) cout << v[i];
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