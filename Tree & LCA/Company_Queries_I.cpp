#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2e5+1, M = 20; 

vector<ll> adj[N]; 
int depth[N], Par[N][M]; 


//binary lifting

void dfs(ll cur, ll par)
{
    depth[cur] = depth[par] + 1; 
    Par[cur][0] = par; 
    for(int j=1;j<M;j++)
    {
        Par[cur][j] = Par[Par[cur][j-1]][j-1]; 
    }

    for(auto child: adj[cur])
    {
        if(child!=par)
        {
            dfs(child, cur); 
        }
    }
}

ll getKthAncestor(int node, int k)
{
    if(depth[node]<k) return -1; 
    for(int j=M-1;j >=0; j--)
    {
        if((1<<j)&k)
        {
            node = Par[node][j]; 
        }
    }
    return node;
}





void solve()
{
    ll n, q; 
    cin >> n >> q; 
    for(int i=2;i<=n; i++)
    {
        ll x; 
        cin >> x; 
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1, 0);

    while(q--)
    {
        ll x, k; 
        cin >> x >> k; 
        if(getKthAncestor(x, k)==0) cout << -1 << endl; 
        else cout << getKthAncestor(x, k) << endl;  
    }
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