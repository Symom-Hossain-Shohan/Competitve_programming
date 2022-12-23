#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, k ;
    cin >> a >> b >> k; 
    vector<bool> is_prime(b+1, true); 
    vector<ll> primes; 
    primes.push_back(2); 
    for(int i = 3 ; i*i<=b; i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i; j<=b; j+=2*i) is_prime[j] = false; 
        }
    }
    for(int i= 3; i<=b;i+=2) if(is_prime[i]) primes.push_back(2); 
    if(primes.size()<k) cout << -1 << endl; 
    else 
    {
        ll n = primes.size() - k; 
        ll t = primes[n]; 
        cout << t<< endl; 
        cout << min(b-a+1, t) << endl; 
    } 
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