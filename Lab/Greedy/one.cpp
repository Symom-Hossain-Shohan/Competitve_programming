#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, n; 

ll bigmod(ll x, ll n)
{
    if(n==0) return 1; 

    if(n%2==0) 
    {
        ll res = bigmod(x, n/2);
        return res*res; 
    }
    else 
    {
        return x*bigmod(x, n-1);
    }
}


void solve()
{
    cin >> x >> n; 
    cout << bigmod(x, n) << endl; 
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