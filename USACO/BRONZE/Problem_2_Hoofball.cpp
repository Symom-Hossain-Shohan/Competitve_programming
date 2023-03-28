#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> adj[101];
vector<bool> visited(101, false); 

void dfs(ll s)
{
    visited[s] = true; 
    for(auto child: adj[s])
    {
        if(visited[child]==false) dfs(child);
    }
}

void solve()
{
    ll n; 
    cin >> n;
    if(n==1)
    {
        cout << 1 << endl;
        return; 
    }
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    adj[v[0]].push_back(v[1]); 
    adj[v[n-1]].push_back(v[n-2]);  
    for(int i=1;i<n-1;i++)
    {
        if(v[i]-v[i-1]<=v[i+1]-v[i]) adj[v[i]].push_back(v[i-1]); 
        else adj[v[i]].push_back(v[i+1]); 
    }

    ll cnt = 0; 
    for(auto i: v)
    {
        if(visited[i]==false) 
        {
            cnt++; 
            dfs(i);
        }
    }

    cout << cnt << endl; 
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