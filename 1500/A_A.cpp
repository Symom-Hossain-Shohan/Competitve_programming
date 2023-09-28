#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    ll np = n-m; 
    if(m==0)
    {
        cout << 0 << ' ' << 0 << endl; 
    }
    else 
    {
        cout << m << ' ' << max(1ll, (m+np)/(np+1)) << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}