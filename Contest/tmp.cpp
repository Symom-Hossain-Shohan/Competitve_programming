#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y; 
    cin >>x >> y; 

    ll gcd = __gcd(x, y);
    ll a = x/gcd - 1; 
    ll b = y/gcd - 1; 

    ll n = y*x - y; 
    cout << n << endl; 
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