#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    if (is_sorted(v.begin(), v.end()) && v.back() >= v[0])
        cout << 0 << endl;
    else
    {
        vector<ll> tm = v;
        sort(tm.begin(), tm.end());
        ll ans = 0;
        ll i = n - 1;
        while (v[i] == tm[i])
            i--;
        for (; i >= 0; i--)
            ans = max(ans, v[i]);

        cout << ans << endl;
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