#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll good(ll number)
{
    ll traillingZeros = 0;
    for (ll i = 5; i <= number; i *= 5)
    {
        traillingZeros += (number / i);
    }
    return traillingZeros;
}

void solve()
{
    ll n;
    cin >> n;
    ll l = 1, r = 1e18, ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll z = good(mid);
        if (z > n)
            r = mid - 1;
        else if (z < n)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    if (ans == -1)
        cout << "impossible\n";
    else
        cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}