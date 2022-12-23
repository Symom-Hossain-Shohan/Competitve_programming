#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll ans = 0; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    for(int i = 0;i<n;i+=2)
    {
        ans += v[i+1]-v[i]; 
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}