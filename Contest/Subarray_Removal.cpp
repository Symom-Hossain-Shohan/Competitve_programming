#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    map<ll,ll> mp; 
    for(int i = 0; i<n ;i++)
    {
        ll x; 
        cin >> x; 
        mp[x] = i + 1; 
    }

    ll mx = 0, mn = n+1; 
    ll cnt = 0; 
    ll ans = 0;
    for(int i = n; i>1; i--)
    {
        mx = max(mx, mp[i]);
        mn = min(mn, mp[i]);
        cnt++; 
        if(mx-mn+1==cnt) 
        {
            ans = max(ans, cnt);
        }

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