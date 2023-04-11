#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> vv; 
map<string, vector<string>> adj; 
map<string, bool> visited; 
vector<string> ans; 


void dfs(string source)
{
    visited[source] = true; 
    ans.push_back(source);

    for(auto child: adj[source])
    {
        if(visited[child]!=true) dfs(child); 
    }
}

void solve()
{
    vv = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"}; 
    ll n; 
    cin >> n; 
    for(int i = 0;i<=n;i++)
    {
        string s; 
        getline(cin, s);
        string u, v; 
        for(int j=0;j<(int)s.size(); j++)
        {
            if(s[j]==' ') break;
            else u.push_back(s[j]); 
        }
        for(int j=(int)s.size()-1;j>=0;j--)
        {
            if(s[j]==' ') break;
            else v.push_back(s[j]);
        }

        reverse(v.begin(), v.end()); 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(vv.begin(), vv.end()); 
    for(auto i: vv)
    {
        if(visited[i]==true or adj[i].size()>=2)
        {
            continue;
        }
        else dfs(i);
    }

    for(auto i: ans) cout << i << '\n';
    //cout << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}