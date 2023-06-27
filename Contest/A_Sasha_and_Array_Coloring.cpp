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

    ll ans = 0; 
    for(int i=0, j=n-1;i<=j; i++, j--) ans += v[j] - v[i]; 

    cout << ans << endl;  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}