#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    vector<ll> w(n+1);  
    for(int i=1;i<=n;i++) cin >> w[i]; 
    vector<ll> adj[n+1]; 
	for(int i=1;i<n;i++)
	{
		ll u, v; 
		cin >> u >> v; 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	ll level[n+1]; 
	ll visited[n+1]; 
	memset(visited, 0, sizeof(visited)); 

	level[1] = 0;  
	visited[1] = 1;  
	vector<ll> even, odd;  
	queue<ll> q; 
	q.push(1);  
	while (!q.empty()) 
	{
		ll par = q.front(); 
		q.pop();  
		if(level[par]!=2==0) even.push_back(par); 
		else odd.push_back(par); 
		for(auto child: adj[par])
		{
			if(!visited[child])
			{
				visited[child] = 1 ; 
				level[child] = level[par] = 1;  
				q.push(par); 
			}
		}
	}
	

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}