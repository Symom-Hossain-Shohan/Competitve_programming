#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b; 
    cin >> a >> b; 
    cout << 2 << endl; 
    cout << a-1 << ' ' << 1 << endl; 
    cout << a << ' ' << b << endl; 
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