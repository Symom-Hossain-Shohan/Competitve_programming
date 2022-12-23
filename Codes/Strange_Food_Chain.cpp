#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 50001; 

int parent[mx] ; 
int sz[mx] ; 

void make(int v)
{
    parent[v] = v ; 
    sz[v] = 1 ; 
}

int find(int v)
{
    if(v == parent[v]) return v ; 
    return parent[v] = find(parent[v]) ; 
}

void Union(int a, int b)
{
    a = find(a) ; 
    b = find(b) ; 
    if(sz[a] < sz[b]) swap(a, b) ; 
    if(a != b) 
    {
        parent[b] = a ; 
        sz[a] += sz[b] ; 
    }
}

void solve()
{
    int n, k ;
    cin >> n >>  k ;
    int ans = 0 ; 

    for(int i = 1 ;i<=n; i++) make(i) ; 

    for(int i=0;i<k;i++)
    {
        int t, u, v ;
        cin >> t >> u >> v; 
        if(u>n or v>n) ans++,cout << i << endl; 
        else 
        {
            if(t==1) Union(u, v) ;
            else 
            {
                if(find(u) == find(v)) ans++, cout << i << endl ;  
            } 
        }
    }

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