#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, ar[205], lim, memo[205][10];

ll dp(ll pos, ll op)
{
    if (pos == lim)
        return 0;
    ll &ans = memo[pos][op];

    if (ans == -1)
    {
        ll cur = 0, res = 1e18;
        for (int i = pos + 1; i < lim; i++)
        {
            cur += (i - pos) * ar[i];
            if (op < k)
                res = min(res, cur + dp(i + 1, op + 1));
        }
        ans = min(res, cur + dp(lim, op));
    }
    return ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    for (int i = n + 1; i <= 2 * n; i++)
        ar[i] = ar[i - n];
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        memset(memo, -1, sizeof(memo));
        lim = i + n;
        ans = min(ans, dp(i, 1));
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}