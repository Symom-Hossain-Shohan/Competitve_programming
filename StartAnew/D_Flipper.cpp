#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n), ans(n);
    for (auto &i : v)
        cin >> i;
    ans = v;
    reverse(ans.begin(), ans.end());
    vector<ll> tmp;
    tmp.push_back(v.back());
    for (int i = 0; i < n - 1; i++)
        tmp.push_back(v[i]);
    // for(auto i: tmp) cout << i << ' ';
    // cout << endl;

    ans = max(ans, tmp);
    tmp.clear();

    ll x = v[1], ix = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i] > x)
        {
            x = v[i], ix = i;
        }
    }

    // for(int i=ix; i<n ;i++) tmp.push_back(v[i]);
    for (int i = 0; i < ix; i++)
    {
        tmp.clear();
        for (int j = ix; j < n; j++)
            tmp.push_back(v[j]);
        for (int j = ix - 1; j >= i; j--)
            tmp.push_back(v[j]);

        if (i != 0)
        {
            for (int j = 0; j < i; j++)
                tmp.push_back(v[j]);
        }
        ans = max(ans, tmp);
    }

    ans = max(ans, tmp);
    for (auto i : ans)
        cout << i << ' ';
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