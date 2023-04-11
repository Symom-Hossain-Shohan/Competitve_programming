#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, c, d; 
    cin >> n >> c >> d; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    map<ll,ll> mp; 
    ll dup = 0,  ans = n * c + d, mx = -1; 
    for(int i=0;i<n;i++)
    {
        mx = max(mx, v[i]); 
        mp[v[i]]++; 
        if(mp[v[i]]>1) dup++;

        ll cost = dup * c + (n-i-1) * c + (mx - mp.size()) * d; 
        ans = min(ans, cost); 
    }
    cout << ans << endl; 
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