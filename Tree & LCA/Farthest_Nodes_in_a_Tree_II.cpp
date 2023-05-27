#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 3e4 + 1;
vector<ll> tree[N];
map<pair<ll, ll>, ll> cost;

vector<ll> dist;
ll farthestNode, maxDist = -1;

void dfs(ll src, ll par, ll d)
{
    dist[src] = d;
    if (d > maxDist)
    {
        farthestNode = src;
        maxDist = d;
    }
    for (auto child : tree[src])
    {
        if (child != par)
        {
            dfs(child, src, d + cost[{src, child}]);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        tree[i].clear();
    cost.clear();

    for (int i = 1; i < n; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back(v);
        tree[v].push_back(u);

        cost[{u, v}] = w;
        cost[{v, u}] = w;
    }
    maxDist = -1;
    dist.resize(n, 0);
    dfs(0, -1, 0);

    maxDist = -1;
    dist.resize(n, 0);
    dfs(farthestNode, -1, 0);
    vector<ll> p_diff = dist;

    maxDist = -1;
    dist.resize(n, 0);
    dfs(farthestNode, -1, 0);

    vector<ll> q_diff = dist;

    for (int i = 0; i < n; i++)
        cout << max(p_diff[i], q_diff[i]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}