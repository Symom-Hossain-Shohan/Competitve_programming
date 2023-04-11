#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, c;
    cin >> r >> c;
    ll x = 1e18, y = 1e18, z = 1e18;
    pair<ll, ll> p1, p2, p3;
    cout << "? 1 1" << endl;
    cin >> x;
    if (x == 0)
    {
        cout << "! 1 1" << endl;
        return;
    }
    p1 = {1, 1};
    p2 = {1, min(c,1 + x)};
    p3 = {min(r,1 + x), 1};
    if (p2.second <= c)
    {
        cout << "? " << p2.first << ' ' << p2.second << endl;
        cin >> y;
        if (y == 0)
        {
            cout << "! " << p2.first << ' ' << p2.second << endl;
            return;
        }
    }
    if (p3.first <= r)
    {
        cout << "? " << p3.first << ' ' << p3.second << endl;
        cin >> z;
        if (z == 0)
        {
            cout << "! " << p3.first << ' ' << p3.second << endl;
            return;
        }
    }

    pair<ll, ll> a1, a2;
    a1 = {p2.first + y, p2.second};
    a2 = {p3.first, p3.second + z};

    if (max(abs(a1.first - 1ll), abs(a1.second - 1ll)) == x and (max(abs(a1.first - p2.first), abs(a1.second - p2.second)) == y) and (max(abs(a1.first - p3.first), abs(a1.second - p3.second)) == z ) and a1.first <= r and a1.second <= c and y!=1e18)
    {
        cout << "! " << a1.first << ' ' << a1.second << endl;
    }
    else
    {
        cout << "! " << a2.first << ' ' << a2.second << endl;
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