#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> adj[200005]; 
vector<ll> leaf(200005); 

void dfs(ll source, ll par)
{
    bool ok = true; 
    for(auto child: adj[source])
    {
        if(child != par)
        {
            dfs(child, source); 
            leaf[source] += leaf[child]; 
            ok = false; 
        }
    }
    if(ok) leaf[source] = 1; 
}


void solve()
{
    ll n; 
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear(), leaf[i] = 0; 

    for(int i=1;i<n;i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    dfs(1, 0); 

    //for(int i=1;i<=n;i++) cout << i << ' ' << leaf[i] << endl; 
    ll q; 
    cin >> q; 
    while(q--)
    {
        ll x, y; 
        cin >> x >> y; 
        cout << leaf[x] * leaf[y] << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}