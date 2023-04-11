#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, x, p; 
    cin >> n >> x >> p; 
    bool ok = false; 
    ll r = (n-x) % n; 
    for(int i = 1;i<=min(2LL*n, p); i++)
    {
        ll m = (i*(i+1LL))/2LL; 
        m %= n; 
        if(m%n == r) 
        {
            ok = true; 
            break;; 
        }
    }
    if(ok) cout << "Yes\n";
    else 
        cout << "No\n"; 
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