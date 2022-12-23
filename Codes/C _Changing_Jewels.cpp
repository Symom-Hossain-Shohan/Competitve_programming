#include<bits/stdc++.h>
#include <cstring>
using namespace std;

typedef long long ll;
ll n, x, y;

ll blue_lev[11], red_lev[11];
ll blue(ll n);
ll red(ll n);

ll red(ll n)
{
	if (n == 2)
	{
		return  x*blue(2);
	}
	else if (red_lev[n] != -1) return  red_lev[n];
	else
	{
		return red_lev[n] = red(n - 1) + x * blue(n);
	}
}

ll blue(ll n)
{
	if (n == 2) return y;
	else if (blue_lev[n] != -1) return blue_lev[n];
	else
	{
		return  blue_lev[n] = red(n - 1) + y * blue(n - 1);
	}
}



void solve()
{
	cin >> n >> x >> y;
	memset(blue_lev, -1, sizeof blue_lev);
	memset(red_lev, -1, sizeof( red_lev));

	cout << red(n) << endl;
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