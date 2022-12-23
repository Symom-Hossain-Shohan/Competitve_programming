#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    map<ll,ll> m;
    vector<ll> v(n);
    for(auto &i: v)
    {
        cin >> i;
        m[i]++;
    }
    
    ll mx=-1e18;
    for(auto i: m) mx=max(i.second,mx);
    ll tm=mx;
    n-=mx;
    ll ans=n;
    while(n>0)
    {
        n-=tm;
        ans++;
        tm*=2;
    }
    cout << ans << endl;
}

int main()
{
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}