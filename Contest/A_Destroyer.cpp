#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 

    map<ll,ll> mp; 
    for(auto i: v) mp[i]++; 
    bool ok = true; 

    for(int i=1;i<=100; i++)
    {
        if(mp[i]>mp[i-1]) ok = false; 
    }

    if(ok) cout << "YES\n"; 
    else cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}