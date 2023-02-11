#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    ll sum = 0;  
    for(auto &i: v) cin >> i, sum += i; 
    sort(v.begin(), v.end());

    ll s1 = sum; 
    sum = 0;
    ll s2 = 0;  
    for(int i = 0;i<n;i++)
    {
        s2 += i*v[i] - sum; 
        sum += v[i];
    } 

    ll ans = s1 + 2*s2; 

    cout << ans/(__gcd(ans, n)) << ' ' << n/__gcd(ans, n) << endl; 


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