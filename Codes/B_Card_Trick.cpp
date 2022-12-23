#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    vector<ll> a(n);
    for(auto &i: a) cin >> i; 
    ll sum =0, m ;
    cin >> m; 
    while(m--)
    {
        ll x; 
        cin >> x; 
        sum += x; 
    }
    sum %= n; 
    cout << a[sum] << endl; 
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