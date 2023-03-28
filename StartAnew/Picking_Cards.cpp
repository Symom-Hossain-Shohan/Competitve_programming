#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7; 

void solve()
{
    ll n; 
    cin >> n; 
    map<ll,ll> mp; 
    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
    }
    ll val = 0, res = 1; 
    for(int i=0;i<n;i++)
    {
        val += mp[i]; 
        if(val==0)
        {
            cout << 0 << endl; 
            return; 
        }
        else 
        {
            res = (res % mod) * (val %mod); 
        }
        val -= 1; 
    }

    cout << res % mod << endl; 
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