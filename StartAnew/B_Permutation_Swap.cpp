#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (abs(x - i) != 0)
            v.push_back(abs(x - i));
    }
    ll gcd = v[0];
    for (auto i : v)
        gcd = __gcd(gcd, i);
    cout << gcd << endl;
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