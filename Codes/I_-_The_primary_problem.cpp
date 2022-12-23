#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx = 1000005; 

vector<bool> is_prime(mx, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    is_prime[0] = is_prime[1] = false; 
    for(int i = 4;i<=1000000;i+=2) is_prime[i] = false; 
    for(int j = 3 ; j*j<= 1000000; j+=2)
    {
        if(is_prime[j])
        {
            for(int i= j*j; i<=1000000;i+=2*j) is_prime[i] = false; 
        }
    }

    for(int i=3;i<=1000000;i+=2) if(is_prime[i]) primes.push_back(i);
}

void solve()
{
    ll n; 
    while(cin >>  n)
    {
        if(n==0) break;
        bool ok = false; 
        for(int i=0;primes[i]<=n and i<(int)primes.size(); i++)
        {
            if(is_prime[n-primes[i]])
            {
                cout << n << ":\n"; 
                cout << primes[i] << "+" << n-primes[i] << endl; 
                ok = true; 
                break;
            }
        }
        if(!ok)
        {   
            cout << n << ":\n";
            cout << "NO WAY!\n";
        }
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