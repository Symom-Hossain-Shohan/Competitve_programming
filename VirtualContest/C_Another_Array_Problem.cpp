#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    if(n>3)
    {
        cout << n * (*max_element(v.begin(), v.end())) << endl; 
    }
    else if(n==2)
    {
        cout << max(v[0] +v[1], 2*abs(v[0]-v[1])) << endl; 
    }
    else 
    {
        cout << max({3*v[0], 3*v[2], 3*abs(v[0]-v[1]), 3*abs(v[1]-v[2]), v[0] + v[1] +v[2]}) << endl; 
    }
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