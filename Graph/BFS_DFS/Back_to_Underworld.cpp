//https://lightoj.com/problem/back-to-underworld
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 200001;
vector<ll> adj[mx];
ll vampires , lykens; 
ll parent[mx];
ll visited[mx];

void bfs(ll node)
{
    priority_queue<ll> pq; 
    pq.push(node);
    visited[node] = 1; 
    while(!pq.empty())
    {
        ll cur = pq.top();
        pq.pop();
        for(auto child: adj[cur])
        {
            if(visited[child]==-1)
            {
                visited[child] = 1; 
                if(parent[cur]== 1)
                {
                    lykens++; 
                    parent[child ]= 2; 
                }
                else 
                {
                    vampires++; 
                    parent[child] = 1; 
                }
                pq.push(child);
            }
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=0;i<mx;i++) adj[i].clear();
    ll source = -1; 
    set<ll> st; 
    for(int i=0;i<n;i++)
    {
        ll u, v; 
        cin >> u >> v ; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        source = u; 
        st.insert(u);
        st.insert(v);
    }
    memset(parent, -1, sizeof(parent));
    memset(visited, -1, sizeof(visited));
    ll ans = 0; 
    for(auto i: st)
    {
        if(visited[i]==-1)
        {
            vampires = 1, lykens =0; 
            parent[i] = 1; 
            bfs(i);
            ans += max(vampires, lykens);
        }
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
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}