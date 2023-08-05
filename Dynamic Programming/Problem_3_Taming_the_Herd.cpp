#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll ar[101], lim;
ll memo[101][101];

ll dp(ll pos, ll op)
{
    if (pos == n)
    {
        if (op == lim)
            return 0;
        else
            return 1e18;
    }
    if (memo[pos][op] != -1)
        return memo[pos][op];
    ll cnt = 0, ans = 1e18;
    for (int i = pos; i < n; i++)
    {
        if (ar[i] != i - pos)
            cnt++;
        // cout << ar[i] << ' ' << pos << ' ' << cnt << endl;
        ans = min(ans, cnt + dp(i + 1, op + 1));
    }

    // cout << pos << ' ' << op << ' ' << ans << endl;

    return memo[pos][op] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    for (int i = 1; i <= n; i++)
    {
        lim = i;
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0) << endl;
    }
    // lim = 1;
    // cout << dp(0,0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}