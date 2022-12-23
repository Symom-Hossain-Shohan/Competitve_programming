#include<bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll>	adj[33]; 


vector<bool> vis(33, false);  
void dfs(ll node)
{
	vis[node] = true; 
	for(auto child: adj[node])
	{
		if(vis[child] == false) dfs(child);  
	}
}
void solve()
{
    ll n;
    cin >> n;
    set<ll> s; 
    for(int i=0;i<n;i++)
    {
    	ll x; 
    	cin >> x; 
    	int j  = 1; 
    	ll prev = -1;  
    	while(x)
    	{
    		if(x%2==1) 
    		{
    			if(prev==-1) prev = j; 
    			else 
    			{
    				adj[prev].push_back(j); 
    				adj[j].push_back(prev); 
    				prev = j; 
    			}
    			s.insert(j); 
    		}
    		j++;  
    		x/=2; 
    	}
    }

    ll cnt = 0 ;
    for(auto i: s)
    {
    	if(vis[i]==false)
    	{
    		vis[i] = true; 
    		cnt++; 
    		dfs(i);  
    	}
    }
    if(cnt>1) cout << "NO\n"; 
    else cout << "YES\n"; 
    for(int i=0;i<33;i++) vis[i]  = false; 
    s.clear();
	for(int i=0;i<33;i++) adj[i].clear(); 
 
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