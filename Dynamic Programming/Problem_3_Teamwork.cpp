#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll ar[10005], memo[10005];

ll dp(ll pos)
{
    if (pos == n)
    {
        return 0;
    }

    if (memo[pos] != -1)
        return memo[pos];

    ll val1 = ar[pos] + dp(pos + 1), val2 = 0;
    ll mx = 0;
    for (int i = pos; i < (pos + k) and i < n; i++)
    {
        mx = max(mx, ar[i]);
        val2 = max(val2, mx * (i - pos + 1) + dp(i + 1));
    }

    return memo[pos] = max(val1, val2);
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    memset(memo, -1, sizeof(memo));
    cout << dp(0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}