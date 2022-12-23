#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n ;
vector<int> adj[1002] ; 
int parent[1002] ; 
int level[1002] ; 
int LOG = 19 ; 
int up[1001][20] ; 

void dfs(int source, int p, int depth  )
{
    parent[source] = p ; 
    level[source] = depth ; 
    for(auto child: adj[source]) 
    {
        if(child!=source) 
        {
            dfs(child, source, depth+1) ; 
        }
    }
}

void init_lca()
{
    memset(up, -1, sizeof up) ; 
    for(int i=1;i<=n;i++) up[i][0] = parent[i] ; 

    for(int j=1;j<=LOG;j++)
    {
        for(int i = 1;i<=n;i++)
        {
            if(up[i][j-1]!=-1) 
            {
                up[i][j] = up[up[i][j-1]][j-1] ; 
            }
        }
    }
}

int get_lca(int a, int b) 
{
    if(level[a]<level[b]) swap(a, b) ; 

    int k = level[a] - level[b] ; 
    for(int i = LOG ;i>=0;i--) 
    {
        if(k & (1<<i)) a = up[a][i] ; 
    }

    if(a==b) return a ;

    for(int i = LOG ;i>=0;i--)
    {
        if(up[a][i]!=-1 and up[a][i]!=up[b][i])
        {
            a = up[a][i] ; 
            b = up[b][i] ; 
        }
    }

    return parent[a] ; 
}


void solve()
{
    cin >> n ;

    for(int i=1;i<=n;i++) adj[i].clear() ; 

    for(int i=1;i<=n;i++)
    {
        int x ;
        cin >> x ; 
        while(x--)
        {
            int v ;
            cin >> v ; 
            adj[i].push_back(v) ; 
        }
    }

    memset(parent, -1, sizeof parent) ; 
    memset(level, 0, sizeof level) ; 
    dfs(1, 1, 0) ; 

    init_lca() ;  
    int q ;
    cin >> q ; 
    while(q--)
    {
        int a, b ;
        cin >> a >> b ; 
        cout << get_lca(a, b) << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t << ":\n" ; 
        solve();
    }
    return 0;
}