#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n==0) cout << 1 << endl; 
    else if(n==1) cout << 3 << endl; 
    else 
    {
        cout << 3*n << endl; 
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