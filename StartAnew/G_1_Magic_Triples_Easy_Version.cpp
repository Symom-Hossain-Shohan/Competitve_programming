#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    map<ll, ll> mp; 
    ll mx = 1; 
    for(int i=0;i<n; i++)
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
        mx = max(mx, x);
    }

    ll ans = 0; 

    for(auto i: mp) if(i.second>=3) ans += i.second*(i.second-1)*(i.second-2); 

    for(auto i: mp)
    {
        ll x = i.first; 
        if(x*x>mx)
        {
            cout << x << ' ';
        }
    }

    //cout << ans << endl; 
    //for(auto i: mp) cout << i.first << ' ' << i.second << endl;  
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