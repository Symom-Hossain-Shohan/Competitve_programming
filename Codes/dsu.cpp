#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int parent[100005] ; 
int size[100005] ; 

void make(int v)
{
    parent[v] = v ; 
    size[v] = 1 ; 
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

    if(a!=b)
    {
        if(size[a] < size[b]) swap(a, b) ; 
        parent[b] = a; 
        size[a] += size[b] ; 
    }
}


void solve()
{
    
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