#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> nums; 

void solve()
{
    ll n;
    cin >> n;
    if(binary_search(nums.begin(), nums.end(), n)) cout << "YES\n"; 
    else cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll k = 2; k <= 1000; ++k) {
        ll val = 1 + k;
        ll p = k*k;
        for (int cnt = 2; cnt <= 20; ++cnt) {
            val += p;
            if (val > 1e6) break;
            nums.insert(val);            
            p *= k;
        }
    }
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}