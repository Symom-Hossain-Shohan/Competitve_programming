#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll n; 
    cin >> n ; 
    cout << 21 + n/60 << ":" ; 
    n %= 60; 
    if(n<10) cout << "0" << n << endl; 
    else cout << n << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}