#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 
    ll x; 
    cin >> x; 
    ll cnt = 0; 
    for(int i=0;i<n;i++)
    {
        if(x-v[i]>=0) 
        {
            cnt++; 
            x-=v[i];
        }
    }

    cout << cnt <<  " jobs can be done.\n";
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