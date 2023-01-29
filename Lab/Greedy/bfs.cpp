#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> adj[10001];
    ll x = n+1; 
    for(int i=0;i<m;i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        x = min({x, u, v}); 
    }

    vector<bool> visited(n+1);
    for(int i=0;i<=n;i++) visited[i] = false; 

    queue<ll> q; 
    q.push(x);
    visited[x] = true; 
    //cout << x << ' ';
    while(!q.empty())
    {
        ll v = q.front();
        cout << v << ' ';
        q.pop();
        for(auto child: adj[v])
        {
            if(!visited[child])
            {
                visited[child] = true; 
                q.push(child);
            }
        }
    }
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