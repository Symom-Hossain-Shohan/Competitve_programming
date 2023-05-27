#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, s; 
    cin >> n >> s; 
    vector<ll> v(n);

    for(auto &i: v) cin >> i; 
    ll l = 0, r = 0, x = 0, res = 0; 

    for(; r<n; r++)
    {
        x += v[r];
        while(x-v[l]>=s) 
        {
            x -= v[l];
            l++; 
        }
        if(x>=s) res += l+1;
    }
    cout << res << endl; 
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