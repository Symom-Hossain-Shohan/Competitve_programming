#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> adj[(int)2e5+1]; 
vector<ll> sum ; 
ll ans = 0; 
vector<ll> L, R; 

void dfs(int node, int parent)
{
    for(auto i: adj[node])
    {
        if(i!=parent)
        {
            dfs(i, node); 
        }
    }

    if(sum[node]<L[node])
    {
        sum[node] = R[node]; 
        ans++; 
    }
    else if(sum[node]>R[node])
    {
        sum[node] = R[node]; 
    }

    if(parent!=-1) sum[parent] +=  sum[node]; 

}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<=n;i++) adj[i].clear(); 
    for(int i=2;i<=n;i++)
    {
        ll x; 
        cin >> x; 
        adj[i].push_back(x); 
        adj[x].push_back(i); 
    }
    L.resize(n+1), R.resize(n+1); 
    sum.assign(n+1, 0); 
    for(int i=1;i<=n;i++) cin >> L[i] >> R[i]; 

    ans = 0; 
    dfs(1, -1); 
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}