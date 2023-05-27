#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll q;
    cin >> q;
    vector<ll> ans(q);
    ll L = 1, R = 1e18;
    for (int i = 0; i < q; i++)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll a, b, n, l, r;
            cin >> a >> b >> n;
            l = (a - b) * (n - 2) + a + 1, r = (a - b) * (n - 1) + a;
            if (n == 1)
                l = 1, r = a;

            if (l > R or r < L)
                cout << 0 << ' ';
            else
            {
                L = max(l, L), R = min(r, R);
                cout << 1 << ' ';
            }
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ll v1 = max(1ll, (L - b - 1) / (a - b) + 1);
            ll v2 = max(1ll, (R - b - 1) / (a - b) + 1);

            if (v1 == v2)
                cout << v1 << ' ';
            else
                cout << -1 << ' ';
        }
    }
    cout << endl;
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