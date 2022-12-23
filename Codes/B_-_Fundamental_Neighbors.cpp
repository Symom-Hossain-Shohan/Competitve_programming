#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<bool> is_prime(100005, true); 
vector<ll> primes; 

void seive()
{
    primes.push_back(2); 
    for(int i=3;i*i<=100004;i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i;j<=100004;j+=2*i) is_prime[j] = false; 
        }
    }
    for(int i=3;i<=100004;i+=2) if(is_prime[i]) primes.push_back(i); 
}

void solve()
{
    
    ll n; 
    while(cin >> n)
    {
        ll ans = 1; 
        ll x  = n; 
        for(int i=0;primes[i]*primes[i]<=n;i++)
        {
            if(n%primes[i]==0)
            {
                ll cnt = 0; 
                while(n%primes[i]==0)
                {
                    cnt++; 
                    n/= primes[i]; 
                }
                ans *= (ll)pow(cnt, primes[i]); 
            }
        }
        cout << x << ' ' <<  ans << endl; 
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    seive(); 
    
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}