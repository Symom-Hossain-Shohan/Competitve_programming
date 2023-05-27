#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> a(n), b(m); 
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    ll j = 0; 
    for(int i=0;i<m;i++)
    {
        while(j<n and a[j]<b[i]) j++; 
        cout << j << ' ';
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