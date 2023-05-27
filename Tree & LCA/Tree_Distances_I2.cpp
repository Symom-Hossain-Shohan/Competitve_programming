#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
vector<ll> tree[N];

vector<ll> dist; 
ll farthestNode, maxDist; 

void dfs(ll src, ll par, ll d)
{
    dist[src] = d; 
    if(d>maxDist)
    {
        maxDist = d; 
        farthestNode =src; 
    }

    for(auto child: tree[src])
    {
        if(child != par)
        {
            dfs(child, src, 1 + d);
        }
    }
}


void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    maxDist = -1; 
    dist.resize(n+1, 0);
    dfs(1, 0, 0);


    maxDist = -1; 
    dist.resize(n+1, 0);
    dfs(farthestNode, 0, 0);

    vector<ll> p_dif = dist; 

    maxDist = -1; 
    dist.resize(n+1, 0);
    dfs(farthestNode, 0, 0);
    
    vector<ll> q_dif = dist; 

    for(int i=1; i<=n; i++) cout << max(p_dif[i], q_dif[i]) << ' ';


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