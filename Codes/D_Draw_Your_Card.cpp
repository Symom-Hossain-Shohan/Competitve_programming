#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll> under(n + 1, -1);
	vector<ll> pile(n + 1, 0);

	set<ll> s;
	vector<ll> ans(n + 1, -1);
	for (int i = 1; i <= n; i++)
	{
		ll card;
		cin >> card ;
		auto it = s.upper_bound(card);
		if (it == s.end())
		{
			pile[card] = 1;
			s.insert(card);
		}
		else
		{
			under[card] = *it;
			pile[card] =  pile[*it] + 1;
			s.erase(it);
			s.insert(card);
		}

		if (pile[card] == k)
		{
			s.erase(card);
			int x = card;
			for (int j = 0; j < k; j++)
			{
				ans[x] = i;
				x = under[x];
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
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