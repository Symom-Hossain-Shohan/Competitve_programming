#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 100005 ;
const ll mod = 1000000007; 

int parent[mx]; 
int sz[mx]; 

void make(int v) 
{
    parent[v] = v ; 
    sz[v] = 1 ; 
}

int find(int v) 
{
    if(v == parent[v] ) return v ; 
    return parent[v] = find(parent[v]) ; 
}


void Union(int a, int b)
{
    a = find(a) ; 
    b = find(b) ; 

    if(sz[a] < sz[b]) swap(a, b) ; 
    if(a!=b)
    {
        parent[b] = a ; 
        sz[a] += sz[b] ; 
    }
}

void solve()
{
    int n; 
    cin >> n ; 
    for(int i=1;i<=n;i++) make(i) ; 
    vector<int> a(n), b(n), c(n) ; 
    for(auto &i: a) cin >> i ; 
    for(auto &i: b) cin >> i ; 
    for(auto &i: c) cin >> i ; 

    for(int i=0;i<n;i++)
    {
        Union(a[i], b[i]) ; 
        if(a[i]==b[i]) c[i] = b[i] ; 
    }
    set<int> s ; 
    for(int i=1;i<=n;i++) s.insert(find(i)) ; 

    for(int i=0;i<n;i++)
    {
        if(c[i]) s.erase(find(c[i])) ; 
    }

    ll ans = 1 ; 
    for(int i=1;i<=(int)s.size() ;i++) ans = (ans*2) % mod ; 

    cout << ans << endl ; 
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