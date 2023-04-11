#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n; 
vector<ll> v;

bool isPrime(ll x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false; 
    }
    return true;
}

bool isGood(ll x)
{
    for(int i=0;i<n;i++)
    {
        if(__gcd(x, v[i])==1) return false; 
    }
    return true; 
}

void solve()
{
    cin >> n; 
    v.resize(n);
    for(auto &i: v) cin >> i; 

    vector<ll> primes; 
    primes.push_back(2);
    for(int i=3;i<=50;i++)
    {
        if(isPrime(i)) primes.push_back(i);
    }

    ll p = primes.size();
    //cout << p << endl; 
    ll ans = 1e18; 
    for(int i=0;i<(1<<p); i++)
    {
        ll t = 1; 
        for(int j=0;j<p;j++)
        {
            if((1<<j) & i) t *= primes[j]; 
        }
        if(isGood(t)) ans = min(ans, t);
    }
    cout << ans << endl; 
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