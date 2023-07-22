#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x;
    cin >> x;
    if (x % 2)
    {
        cout << -1 << endl;
    }
    else
    {
        ll a = x + x / 2;
        ll b = x / 2;
        if ((a ^ b) == x)
        {
            cout << a << ' ' << b << endl;
        }
        else
            cout << -1 << endl;
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