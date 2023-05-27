#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_VAL = 1e6;

ll cnt[MAX_VAL + 1];

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ans += (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
        for (ll b = 2; a[i] * b * b <= MAX_VAL; ++b)
        {
            ans += cnt[a[i] * b] * cnt[a[i] * b * b];
        }
    }
    cout << ans << "\n";
    for (ll i = 0; i < n; ++i)
    {
        --cnt[a[i]];
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