#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
vector<ll> ar;
ll mod = 1e9 + 7;

ll memo[100005][101];

ll dp(ll pos, ll prev)
{
    if (pos == n)
        return 1;

    if (memo[pos][prev] != -1)
        return memo[pos][prev];
    if (ar[pos]!=0)
    {
        if (abs(prev - ar[pos]) <= 1)
            return memo[pos][prev] = dp(pos + 1, ar[pos]) % mod;
        else
            return memo[pos][prev] = 0;
    }
    else
    {
        ll ans1 = dp(pos + 1, prev) % mod;
        ll ans2 = 0; 
        if(prev-1>=1)
         ans2 = (dp(pos + 1, prev - 1) * (prev - 1 > 0)) % mod;
        ll ans3 = 0; 
        if(prev+1<=m)
         ans3 = (dp(pos + 1, prev + 1) * (prev + 1 <= m)) % mod;
        return memo[pos][prev] = (ans1 + ans2 + ans3) % mod;
    }
}

void solve()
{
    cin >> n >> m;
    ar.resize(n);
    for (auto &i : ar)
        cin >> i;
    memset(memo, -1, sizeof(memo));
    if (ar[0])
    {
        cout << dp(1, ar[0]) % mod << endl;
    }
    else
    {
        ll ans = 0;
        for (int i = 1; i <= m; i++)
            ans = (ans + dp(1, i) %mod) % mod;
        cout << ans << endl;
    }
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