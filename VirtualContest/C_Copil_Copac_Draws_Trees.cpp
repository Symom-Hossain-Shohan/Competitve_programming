#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
vector<pair<ll, ll>> edge[N];
ll memo[N], id[N];

void dfs(ll cur)
{
    for (auto v : edge[cur])
    {
        if (memo[v.first] == 0)
        {
            memo[v.first] = memo[cur] + (v.second <= id[cur]);
            id[v.first] = v.second;
            dfs(v.first);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    for(int i = 0;i<=n; i++) edge[i].clear();
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }

    for (int i = 0; i <= n; i++)
        memo[i] = 0, id[i] = 0;
    memo[1] = 1;
    dfs(1);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, memo[i]);
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