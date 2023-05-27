#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e6+ 1; 

vector<ll> primes; 
vector<bool> isPrime(N, true);

void sieve()
{
    primes.push_back(2);
    for(int i = 3; i*i<N; i+=2)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j<N; j+=2*i)
            {
                isPrime[j] = false; 
            }
        }
    }

    for(int i = 3;i<N; i+=2) if(isPrime[i]) primes.push_back(i); 
}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    ll d = n; 
    if(n==1)
    {
        cout << "YES\n"; 
        return;
    }
    for(int i=0; primes[i]*primes[i]<=n; i++)
    {
        if(n%primes[i]==0) 
        {
            d = primes[i];
            break;
        }
    }

    if(d>m) cout << "YES\n";
    else cout << "NO\n";  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    sieve();
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}