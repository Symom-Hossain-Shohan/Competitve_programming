#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >>  k; 
    ll sum = 0; 
    for(int i = 0; i < k; i++)
    {
        ll x; 
        cin >> x; 
        sum += x; 
    }
    if(sum >= n) cout << "Yes\n"; 
    else cout << "No\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}