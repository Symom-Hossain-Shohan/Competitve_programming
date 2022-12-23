#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx =20000005; 
vector<bool> is_prime(mx, true);
vector<ll> primes; 
vector<pair<ll,ll>> twin_primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=20000000;i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i;j<=20000000;j+=2*i) is_prime[j] = false; 
        }

    }

    for(int i = 3;i<=20000000; i+=2) if(is_prime[i]) primes.push_back(i);
}

void solve()
{
    for(int i = 1;i<(int)primes.size(); i++)
    {
        if(primes[i]-primes[i-1]==2) twin_primes.push_back({primes[i-1], primes[i]}); 
    }
    ll n; 
    while(cin >> n)
    {
        cout << "(" << twin_primes[n-1].first << ", " << twin_primes[n-1].second << ")\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    sieve();
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}