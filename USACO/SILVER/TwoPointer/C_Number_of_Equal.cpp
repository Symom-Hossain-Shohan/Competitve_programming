#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >>m; 
    map<ll,ll> mp; 
    for(int i=0;i<n;i++) 
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
    }
    ll ans = 0; 
    for(int i=0;i<m;i++)
    {
        ll x; 
        cin >> x; 
        ans += mp[x];
    }
    cout << ans << endl; 
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