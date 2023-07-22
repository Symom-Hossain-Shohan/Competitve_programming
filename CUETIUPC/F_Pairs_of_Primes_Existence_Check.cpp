#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> isPrime(1000006, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=1000000; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=1000000; j+=2*i) isPrime[j] = false; 
        }
    }

    for(int i=3;i<=1000000; i+=2) if(isPrime[i]) primes.push_back(i);
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=0; primes[i]<=n; i++)
    {
        ll x = n - primes[i];
        if(binary_search(primes.begin(), primes.end(), x)) 
        {
            //cout << x << ' ' << primes[i] << endl; 
            cout << "YES\n"; 
            return; 
        }
        
    }
    cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    sieve();
    cout << primes.back() << endl; 
    // for(int i=0; i<=10; i++) cout << primes[i] << endl; 
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}
