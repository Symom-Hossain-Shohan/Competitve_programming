#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
vector<ll> tree[N];
ll  n; 
vector<ll> subtreeAns, subtreeNodes, ans; 

void dfs_subtree(ll src, ll par)
{
    ll subAns = 0, subNodes = 1; 
    for(auto child: tree[src])
    {
        if(child != par)
        {
            dfs_subtree(child, src);
            subNodes += subtreeNodes[child];
            subAns += subtreeAns[child] + subtreeNodes[child];
        }
    }

    subtreeAns[src] = subAns; 
    subtreeNodes[src] = subNodes; 
}

void dfs_ans(ll src, ll par, ll partial_ans)
{
    ans[src] = subtreeAns[src] + partial_ans + n - subtreeNodes[src];
    for(auto child: tree[src])
    {
        if(child != par)
        {
            dfs_ans(child, src, ans[src] - (subtreeAns[child] + subtreeNodes[child]));
        }
    }
}

void solve()
{
    
    cin >> n; 
    for(int i=1; i<n ;i++)
    {
        ll u, v; 
        cin >> u >> v; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    subtreeAns.resize(n+1), subtreeNodes.resize(n+1);
    dfs_subtree(1, 0);

    ans.resize(n+1);

    dfs_ans(1, 0, 0);
    ans[1] = subtreeAns[1];
    for(int i = 1;i<=n; i++) cout << ans[i] << ' ';
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