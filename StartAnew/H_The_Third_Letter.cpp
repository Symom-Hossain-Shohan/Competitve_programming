#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 2e5 + 1;
vector<ll> adj[mx];
vector<ll> cost[mx];
vector<ll> visited, dist;

void dfs(ll cur)
{
    // dist[cur] = 0;
    visited[cur] = 1;
    for (int i = 0; i < (int)adj[cur].size(); i++)
    {
        if (visited[adj[cur][i]] == 0)
        {
            // dist[adj[cur][i]] = dist[cur] + cost[cur][i];
            // cout << cur << ' ' << adj[cur][i] << ' ' << cost[cur][i] << ' ';
            dist[adj[cur][i]] = dist[cur] + cost[cur][i];
            visited[adj[cur][i]] = 1;
            // cout << dist[adj[cur][i]] << endl;
            // cout << "HI";
            dfs(adj[cur][i]);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        adj[i].clear(), cost[i].clear();

    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        a[i] = u, b[i] = v, d[i] = c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(-c);
    }
    // cout << cost[1][0] << endl;

    visited.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 1; i <= n; i++)
        visited[i] = 0, dist[i] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    bool ok = true;

    for (int i = 0; i < n; i++)
    {
        if (dist[a[i]] + d[i] != dist[b[i]])
            ok = false;
    }

    // for(int i=1;i<=n; i++) cout << dist[i] << ' ';
    // cout << endl;
    // cout << endl;
    // cout << dist[1] << endl
    //      << endl;

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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