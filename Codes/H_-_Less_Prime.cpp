#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx = 10005; 

vector<bool> is_prime(mx, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i = 3; i*i<=10000; i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i; j<=10000; j+= 2*i)
            {
                is_prime[j] = false; 
            }
        }
    }

    for(int i= 3;i<=10000; i+= 2) if(is_prime[i]) primes.push_back(i); 
}

void solve()
{
    ll n; 
    cin >> n ;
    ll dif = -1, ans ; 
    for(int i = 0;primes[i]<=n and i<(int)primes.size(); i++)
    {
        ll x = primes[i];
        for(int j=0;j<=10005;j++)
        {
            if(x*j<=n and x*(j+1)>n)
            {
                if(dif< n - x*j)
                {
                    dif = n - x*j; 
                    ans = x; 
                }
            }
        }
    } 
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    sieve(); 
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}