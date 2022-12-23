#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i;
    sort(v.begin(),v.end());

    ll q;
    cin >> q;
    while(q--)
    {
        ll a, b;
        cin >> a >> b ;
        ll l1=-1,r1=n;
        while(r1>l1+1)
        {
            ll m=(l1+r1)/2;
            if(v[m]>=a) r1=m;
            else l1=m;
        }
        ll l2=-1,r2=n;
        while(r2>l2+1)
        {
            ll m =(l2+r2)/2;
            if(v[m]<=b) l2=m;
            else r2=m;
        }
        cout << l2-r1+1 << ' ';
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