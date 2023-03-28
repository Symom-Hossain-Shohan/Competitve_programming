#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    ll a, b; 
    cin >> a >> b; 
    ll gcd = a*b, lcm = b; 
    ll cnt = 1; 
    for(int i=1;i<n;i++)
    {
        cin >> a >> b; 
        gcd = __gcd(gcd, a*b), lcm = (lcm*b)/__gcd(lcm, b);
        if(gcd%lcm==0) continue;
        else 
        {
            cnt ++; 
            gcd = a*b, lcm = b; 
        }
    }
    cout << cnt << endl; 
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