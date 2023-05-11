#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2)
        cout << -1 << endl;
    else
    {
        //ll cnt = 0;
        map<char, ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            if (mp[s[i]] > n / 2)
            {
                cout << -1 << endl;
                return;
            }
        }
        mp.clear();
        ll cnt = 0, m = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1])
            {
                mp[s[i]]++;
                m = max(m, mp[s[i]]);
                cnt++;
            }
        }

        cout << max(m, (cnt + 1) / 2) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}