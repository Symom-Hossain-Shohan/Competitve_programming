#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    while(k--)
    {
        ll x;
        cin >> x;
        ll l=0,r=n-1;
        bool ok=false;
        while(r>=l)
        {
            ll m=(r+l)/2;
            if(v[m]==x)
            {
                ok=true;
                break;
            }
            else if(v[m]<x) l=m+1;
            else r=m-1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}