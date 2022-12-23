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
        ll l=-1,r=n;
        while(r>l+1)
        {
            ll m=(l+r)/2;
            if(v[m]>=x) r=m;
            else l=m;
        }
        cout << r+1 << endl;
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