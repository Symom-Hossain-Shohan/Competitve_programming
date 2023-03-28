#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    ll sum = 0, ans = 1e18; 
    for(auto &i: v) cin >> i, sum += i; 

    for(int i=0;i<(1<<n); i++)
    {
        ll x = 0; 
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) x += v[j];
        }
        ans =  min(ans,abs( x-(sum-x)));
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