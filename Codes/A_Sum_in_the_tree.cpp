#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> adj[200005];
vector<ll> sum; 
ll res; 

void dfs(ll node, ll val, ll parent)
{
    if(sum[node]==-1) sum[node] = val; 
    else if(val>sum[node])
    {
        res = - 1; 
    }
    else val = sum[node]; 
    for(auto child: adj[node])
    {
        if(child != parent and res!=-1)
        {
            dfs(child, val, node); 
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i = 2;i<=n;i++)
    {
        ll x; 
        cin >> x; 
        adj[i].push_back(x); 
        adj[x].push_back(i); 
    }
    sum.assign(n+1, 0); 
    for(int i = 1;i<=n;i++) cin >> sum[i]; 

    dfs(1, 0, 1); 
    if(res==-1) cout << -1 << endl; 
    else 
    {
        cout << *max_element(sum.begin(), sum.end()) << endl; 
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