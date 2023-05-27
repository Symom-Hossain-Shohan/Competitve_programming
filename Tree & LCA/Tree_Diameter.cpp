#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
vector<ll> adj[N];

ll fNode = -1, maxDist = -1; 

void dfs(ll cur, ll par, ll dist)
{
    if(dist>maxDist)
    {
        maxDist = dist; 
        fNode = cur; 
    }
    for(auto child: adj[cur])
    {
        if(child !=par)
        {
            dfs(child, cur, dist + 1);
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<n;i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    maxDist = -1; 
    dfs(fNode, -1, 0);
    cout << maxDist << endl; 
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