#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    n = 2 * n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(v[i]);
    }

    if (n == 2)
    {
        ans = min(ans, (ll)v[1] - (ll)v[0]);
    }
    if (n == 4)
    {
        ll temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += abs(v[i] - 2LL);
        }
        ans = min(ans, temp);
    }
    if (n % 4 == 0)
    {
        ll temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += abs(v[i] - (-1LL));
        }
        for (int i = 0; i < n; i++)
        {
            temp -= abs(v[i] - (-1LL));
            temp += abs(v[i] - (ll)n / 2LL);

            ans = min(ans, temp);

            temp -= abs(v[i] - (ll)n / 2LL);
            temp += abs(v[i] - (-1LL));
        }
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