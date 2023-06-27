#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k, g; 
    cin >> n >> k >> g; 
    if(n==1)
    {
        cout << 0 << endl; 
    }
    else 
    {
        ll g_2 = (g+1)/2; 
        ll x = g_2 - 1; 

        ll total = k*g - (x*(n-1)); 

        if(total<0) total = (k*g) % x; 
        //cout << total << endl; 
        ll r = total % g; 
        if(r>=g_2)
        {
            cout << k*g- (total + (g-r)) << endl; 
        }
        else cout << k*g - (total - r )<< endl; 

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