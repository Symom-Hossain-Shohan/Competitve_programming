#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1;
vector<ll> adj[N];

ll subOrdinate[N];

ll dfs(ll cur, ll par)
{
    ll sum = 1;
    for (auto child : adj[cur])
    {
        if (child != par)
        {
            sum += dfs(child, cur);
        }
    }
    return subOrdinate[cur] = sum;
}

void solve()
{
    ll n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        cout << subOrdinate[i]-1 << ' ';
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