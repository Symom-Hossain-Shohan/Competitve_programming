#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1234567;

void solve()
{
    ll n;
    cin >> n;
    n--;
    ll ans = 1;
    while (n--)
    {
        ll x;
        cin >> x;
        ans = ((ans % mod) * (x % mod)) % mod;
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