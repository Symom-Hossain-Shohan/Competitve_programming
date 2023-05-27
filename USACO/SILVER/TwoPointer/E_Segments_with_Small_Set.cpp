#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    map<ll,ll> mp; 
    ll l = 0, r = 0, ans = 0;
    for(; r<n; r++)
    {
        mp[v[r]]++; 
        while(mp.size()>k)
        {
            mp[v[l]]--; 
            if(mp[v[l]]==0) mp.erase(v[l]); 
            l++; 
        }
        ans += (r-l+1); 
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