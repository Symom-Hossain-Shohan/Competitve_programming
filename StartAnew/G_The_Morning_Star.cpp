#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first >> vp[i].second;
    }

    sort(vp.begin(), vp.end());

    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
        mp[vp[i].first + vp[i].second]++;

    ll ans = 0;
    for (auto i : mp)
    {
        if (i.second)
            ans += (i.second) * (i.second - 1);
    }
    mp.clear();

    for (int i = 0; i < n; i++)
        mp[vp[i].first - vp[i].second]++;
    for (auto i : mp)
        if (i.second)
            ans += (i.second) * (i.second - 1);

    mp.clear();
    for (int i = 0; i < n; i++)
        mp[vp[i].first]++;

    for (auto i : mp)
        if (i.second)
            ans += (i.second) * (i.second - 1);

    mp.clear();
    for (int i = 0; i < n; i++)
        mp[vp[i].second]++;
    for (auto i : mp)
        if (i.second)
            ans += (i.second) * (i.second - 1);

    cout << ans << endl;
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