#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> adj[10001];
vector<bool> visited(10001);

void dfs(int s)
{
    visited[s] = true; 
    cout << s << ' ';
    for(auto child: adj[s])
    {
        if(!visited[child])
        {
            visited[child] = true; 
            dfs(child);
        }
    }
}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    ll x = n+1; 
    for(int i = 0;i<m;i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        x = min({x, u, v}); 
    }

    for(int i = 0;i<=n;i++) visited[i] = false; 

    dfs(x);
    cout << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}