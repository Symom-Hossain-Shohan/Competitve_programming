#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    ll t = v[0]; 
    for(int i = 1; i < n; i++) 
    {
        t = t ^ v[i]; 
    }
    map<ll,ll> mp; 
    for(auto i: v) 
    {
        ll x = t ^ i; 
        mp[x]++; 
    }
    for(auto i: mp)
    {
        if(i.second == 1) cout << i.first << ' '; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}