#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 1;
ll memo[N][128];
ll n, k;
ll arr[N];

ll dp(ll pos, ll val)
{
    // cout << pos <<' ' << val << endl;

    if (pos == n)
    {
        return (__builtin_popcount(val) == k);
    }

    if (memo[pos][val] != -1 and val != 127)
        return memo[pos][val];

    ll ans;
    ans = dp(pos + 1, val & arr[pos]) + dp(pos + 1, val);
    ans %= mod;
    return memo[pos][val] = ans;
}

void solve()
{
    cin >> n >> k;
    for (int j = 0; j <= n; j++)
    {
        for (int l = 0; l <= 128; l++)
        {
            memo[j][l] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << dp(0, 127) << endl;
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