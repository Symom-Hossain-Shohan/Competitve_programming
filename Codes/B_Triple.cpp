#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n ; 
    cin >> n; 
    map<ll,ll> m ;
    ll ans = -1 ; 
    for(int i=0;i<n;i++)
    {
        ll a; 
        cin >> a ; 
        m[a]++; 
        if(m[a]>=3) ans = a; 
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}