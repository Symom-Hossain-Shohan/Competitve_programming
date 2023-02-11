#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve()
{
    ll n;
    cin >> n; 
    cout << (n*(n-1)*(n-2)*(n-3)*(n-4))/120 * (n*(n-1)*(n-2)*(n-3)*(n-4)) << endl; 
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