#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1005 ; 
int parent[mx] ; 
int sz[mx] ; 
void make(int v) 
{
    parent[v] = v ;
    sz[v] = 1; 
}

int find(int v) 
{
    if(v == parent[v]) return v ; 
    return parent[v] = find(parent[v]) ; 
}
void Union(int a, int b) 
{
    a = find(a) ; 
    b = find(b); 

    if(sz[a] < sz[b]) swap(a, b); 

    if(a!=b)
    {
        parent[b]  = a ;
        sz[a] += sz[b]; 
    }
}

void solve()
{
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++) make(i) ; 
    vector<pair<int,int>> useless ; 
    for(int i=1;i<n;i++)
    {
        int u, v ;
        cin >> u >> v ; 
        if(find(u) == find(v)) useless.push_back({u,v}); 
        else Union(u,v) ; 
    }

    set<int> s; 
    for(int i=1;i<=n;i++) s.insert(find(i));

    vector<int> ans ; 
    for(auto i: s) ans.push_back(i) ; 
    cout << useless.size() << endl; 
    for(int i=0;i<(int)ans.size()-1;i++)
    {
        cout << useless[i].first << ' ' << useless[i].second << ' ' << ans[i] << ' ' << ans[i+1] << endl ; 
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