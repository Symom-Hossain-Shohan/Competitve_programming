#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll n, m;
vector<ll> v;
ll memo[100005][101];

ll dp(ll pos, ll prv)
{
    if (pos == n)
        return 1;
    if (memo[pos][prv] != -1)
        return memo[pos][prv];
    if (abs(v[pos] - prv) > 1)
        return 0;
    if (v[pos] == 0)
    {
        return memo[pos][prv] = ((dp(pos + 1, prv - 1) + dp(pos + 1, prv))%mod + dp(pos + 1, prv + 1)) % mod;
    }
    else
        return memo[pos][prv] = dp(pos + 1, v[pos]);
}

void solve()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, v[0]) << endl;
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