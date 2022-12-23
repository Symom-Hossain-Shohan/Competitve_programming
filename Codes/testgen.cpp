#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;
    bool ok = true;
    ll gcd ;
    while (b != 1)
    {
        gcd = __gcd(a, b);
        if (gcd == 1)
        {
            ok = false;
            break;
        }
        else
        {
            a = gcd;
            while (b % gcd == 0)  b /= gcd;
        }
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}