#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<ll, ll>> H, G;
ll n, m;

ll memo[1001][1001][2];

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    ll x = x1 - x2, y = y1 - y2;
    return x * x + y * y;
}

ll dp(ll i, ll j, ll flag)
{
    if (i > n or j > m)
        return 1e18;
    if (i == n and j == m)
    {
        if (flag == 0)
        {
            return 0;
        }
        else
        {
            return 1e18;
        }
    }
    if (memo[i][j][flag] != -1)
        return memo[i][j][flag];

    ll res1 = 1e18, res2 = 1e18;

    if (flag == 0)
    {
        res1 = dist(H[i].first, H[i].second, H[i + 1].first, H[i + 1].second) + dp(i + 1, j, 0);
    }
    else
    {
        res1 = dist(G[j].first, G[j].second, H[i + 1].first, H[i + 1].second) + dp(i + 1, j, 0);
    }

    if (flag == 0)
    {
        res2 = dist(H[i].first, H[i].second, G[j + 1].first, G[j + 1].second) + dp(i, j + 1, 1);
    }
    else
    {
        res2 = dist(G[j].first, G[j].second, G[j + 1].first, G[j + 1].second) + dp(i, j + 1, 1);
    }

    return memo[i][j][flag] = min(res1, res2);
}

void solve()
{
    cin >> n >> m;
    H.clear(), G.clear();

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        H.push_back({x, y});
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        G.push_back({x, y});
    }
    memset(memo, -1, sizeof(memo));

    cout << (dp(0, 0, 0)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // freopen("checklist.in", "r", stdin);
    // freopen("checklist.out", "w", stdout);
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}