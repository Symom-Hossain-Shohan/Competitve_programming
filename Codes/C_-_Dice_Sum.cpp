#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int s = 1; s <= m; s++)
            {
                if (s + j <= k)
                {
                    dp[i + 1][j + s] += dp[i][j];
                    dp[i + 1][j + s] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans = (ans + dp[n][i]) % MOD;
    cout << ans << endl;
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