#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    int n; 
    cin >> n ; 
    vector<ll > v(n); 
    for(auto &i: v) cin >> i; 

    vector<ll> primes; 
    primes.push_back(2); 
    for(int i=3;i<=50;i+=2)
    {
        bool ok = true; 
        for(auto j: primes)
        {
            if(i%j==0) ok =false;
        }
        if(ok) primes.push_back(i);
    }

    ll ans = 1e18;  
    for(int i=0;i<(1<<15); i++)
    {
        ll res = 1;  
        for(int j=0;j<15;j++)
        {
            if(i & (1<<j))
            {
                res *= primes[j]; 
            }
        }
        bool ok = true; 
        for(int j=0;j<n;j++)
        {
            if(__gcd(res, v[j]) == 1) ok = false;
        }
        if(ok) ans = min(ans, res);  
    } 
    cout << ans << endl; 

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