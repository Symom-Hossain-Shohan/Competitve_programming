#include<bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

bool is_valid(string s)
{
	ll cnt = 0;
	for (auto i : s)
	{
		if (i == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	if (cnt == 0) return true;
	return false;
}

void solve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	ll cnt = 0, q = 0;
	for (auto i : s)
	{
		if (i == '(')cnt++;
		else if (i == ')') cnt--;
		else q++;
	}
	ll open , close;
	open = (-cnt + q) / 2;
	close = open  - (-cnt);
	//cout << open << ' ' << close << endl;
	string tmp = s;
	ll x = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] == '?' and x < open ) tmp[i] = '(', x++;
		else if (tmp[i] == '?') tmp[i] = ')';
	}

	string tm = tmp;
	if (open and close)
	{
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				open--;
				if (open == 0)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (s[j] == '?')
						{
							swap(tmp[i], tmp[j]);
							break;
						}
					}
					break;
				}
			}
		}
		if (is_valid(tm) and !is_valid(tmp)) cout << "YES\n";
		else cout << "NO\n";
	}
	else
	{
		if (is_valid(tmp)) cout << "YES\n";
		else cout << "NO\n";
	}
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