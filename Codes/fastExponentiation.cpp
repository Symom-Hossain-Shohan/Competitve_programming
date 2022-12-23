#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        int last_bit = b & 1;
        if (last_bit == 1)
            ans = ans * a;
        a = a * a;
        b = b >> 1;
    }
    return ans;
}

void solve()
{
    cout << power(2, 8) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}