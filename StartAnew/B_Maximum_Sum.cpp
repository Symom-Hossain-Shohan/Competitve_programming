#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    for (int i = 0; i <= k; i++)
    {
        ll l = k - i, r = i;
        if (l > 0)
            ans = max(ans, v[n - 1 - r] - v[2 * l - 1]);
        else
            ans = max(ans, v[n - 1 - r]);
    }
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