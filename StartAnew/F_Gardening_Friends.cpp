#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
vector<ll> tree[N]; 

vector<ll> depth; 

void dfs_depth(ll src, ll par)
{
    for(auto child: tree[src])
    {
        if(child!= par)
        {
            depth[child] = depth[src] + 1; 
            dfs_depth(child, src); 
        }
    }
}

ll maxDist, maxNode; 

vector<ll> dist; 

void dfs(ll src, ll par, ll d)
{
    if(d>maxDist)
    {
        maxDist = d; 
        maxNode = src; 
    }

    dist[src] = d; 

    for(auto child: tree[src])
    {
        if(child != par)
        {
            dfs(child, src, d + 1); 
        }
    }
}

void solve()
{
    ll n, k, c; 
    cin >> n >> k >> c; 
    for(int i=1;i<=n; i++) tree[i].clear(); 

    for(int i=1; i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        tree[u].push_back(v); 
        tree[v].push_back(u); 
    }

    depth.resize(n+1, 0); 

    dfs_depth(1, 0); 
    maxDist = 0; 
    dist.resize(n+1, 0); 
    dfs(1, 0, 0); 

    dist.resize(n+1, 0); 
    maxDist = 0; 
    dfs(maxNode, 0, 0); 
    vector<ll> dista = dist; 

    maxDist = 0; 
    dist.resize(n+1, 0); 
    dfs(maxNode, 0, 0); 
    vector<ll> distb = dist; 

    ll ans = 0; 
    for(int i = 1; i<=n; i++)
    {
        ll x = max(dista[i], distb[i]); 
        ans = max(ans, x*k - depth[i]*c); 
    }
    cout << ans << endl; 
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