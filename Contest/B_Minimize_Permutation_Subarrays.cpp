#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    map<ll, ll> mp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[x] = i;
    }

    if (mp[n] < mp[1] && mp[1] < mp[2])
        cout << mp[n] << ' ' << mp[1] << "\n";
    else if (mp[n] < mp[2] && mp[2] < mp[1])
        cout << mp[n] << ' ' << mp[2] << "\n";
    else if (mp[n] > mp[1] && mp[1] > mp[2])
        cout << mp[n] << ' ' << mp[1] << "\n";
    else if (mp[n] > mp[2] && mp[2] > mp[1])
        cout << mp[n] << ' ' << mp[2] << "\n";
    else
        cout << 1 << ' ' << 1 << "\n";
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