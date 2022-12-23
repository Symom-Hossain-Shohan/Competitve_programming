#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 2);
    vector<pair<ll, ll>> vp(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        vp[i + 1] = {l, r};
        v[l]++, v[r + 1]--;
    }
    ll mx = -1;
    for (int i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
        mx = max(mx, v[i]);
    }

    vector<ll> ans;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == n-1 and (i < vp[i].first or i > vp[i].second))
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << endl;
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