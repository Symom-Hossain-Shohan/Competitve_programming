#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
const ll mx = 1e5+1; 
vector<ll> adj[mx], cost[mx];

void dfs(ll s)
{
    
}

void solve()
{
    cin >> n ; 

    for(int i=0;i<n-1;i++)
    {
        ll u, v, w;
        cin >> u >> v >> w; 
        adj[u].push_back(v) ;
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    dfs(1);

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