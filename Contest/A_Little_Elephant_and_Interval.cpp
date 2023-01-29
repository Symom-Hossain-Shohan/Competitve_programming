#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll fun(ll x)
{
    if(x<10) return x; 
    ll res = x/10 + 9; 
    ll n = x; 
    while(x>9) x/=10; 

    if(x>(n%10)) res--; 
    return res; 
}

void solve()
{
    ll l, r; 
    cin >> l >> r; 
    cout << fun(r) - fun(l-1) <<endl; 
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