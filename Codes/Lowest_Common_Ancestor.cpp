#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MX = 10002; 


int n ;
vector<int> adj[MX] ; 
int parent [MX] ; 
int level[MX] ; 
int up[MX][20] ; 
int LOG = 19 ; 

void dfs(int source, int p, int depth)
{
    parent[source] = p ; 
    level[source] = depth ; 
    for(auto child: adj[source])
    {
        if(child != source) 
        {
            dfs(child, source, depth+1) ; 
        }
    }
}

void init_lca() 
{
    memset(up, -1, sizeof up) ; 
    for(int i=0;i<n;i++) up[i][0] = parent[i] ; 

    for(int j=1;j<=LOG;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(up[i][j-1]!=-1)
            {
                up[i][j] = up[up[i][j-1]][j-1] ; 
            }
        }
    }

}

int get_lca(int u, int v)
{
    if(level[u]<level[v]) swap(u, v) ; 

    int d = level[u] - level[v] ; 

    for(int i  = LOG;i>=0;i--)
    {
        if(d & (1<<i)) u = up[u][i] ;
    }

    if(u==v) return u ; 

    for(int i = LOG ; i>=0;i--)
    {
        if(up[u][i]!=-1 and up[u][i]!=up[v][i]) 
        {
            u = up[u][i] ; 
            v= up[v][i] ;
        }
    }

    return up[u][0] ; 
}

void solve()
{
    cin >> n ; 
    for(int i=0;i<n;i++)
    {
        int x; 
        cin >> x ; 
        while(x--)
        {
            int v ;
            cin >> v ; 
            adj[v].push_back(v) ; 
        }
    }

    dfs(0, 0, 0) ; 
    init_lca() ; 
    int q ;
    cin >> q ; 
    while(q--)
    {
        int u, v ;
        cin >> u >> v ; 
        cout << get_lca(u, v) << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}