#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, h; 
    cin >> n >> m >> h; 

    vector<ll> car(n), power(m); 
    for(auto &i: car) cin >> i; 
    for(auto &i: power) cin >> i; 

    sort(car.begin(), car.end()); 
    sort(power.begin(), power.end()); 

    ll ans = 0; 

    for(int i=n-1, j=m-1;i>=0 and j>=0; i--, j--)
    {
        ans += min(car[i], power[j]*h); 
    }

    cout << ans << endl; 
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