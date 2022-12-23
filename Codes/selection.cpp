#include<bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> adj[100005];
int visited[100005];
int parent[100005];

void dfs(int source, int par)
{
	visited[source] = 1;
	parent[source] = par;
	for (auto child : adj[source])
	{
		if (!visited[child])
		{
			dfs(child, par);
		}
	}
}

void solve()
{
	ll n, m;
	cin >> n >> m ;
	while (m--)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, 0, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, i);
		}
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		if (parent[u] == parent[v] and parent[u] != -1) cout << "yes\n";
		else cout << "no\n";
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