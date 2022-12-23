#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx = 1001; 

vector<bool> is_prime(mx, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=1000;i+=2)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=1000;j+=2*i) is_prime[j] = false; 
        }
    }
    for(int i=3;i<=1000;i+=2) if(is_prime[i]) primes.push_back(i);
}

bool is_good(ll x)
{
    vector<ll> digits; 
    while(x!=0)
    {
        digits.push_back(x%10);
        x/=10; 
    }

    sort(digits.begin(), digits.end()); 

    do
    {
        ll tmp = 0 ; 
        for(auto i: digits) 
        {
            tmp = tmp*10 + i; 
        }
        if(binary_search(primes.begin(), primes.end(), tmp)==false) return false; 
    } while (next_permutation(digits.begin(), digits.end()));
    return true; 
}

void solve()
{
    sieve();
    vector<ll> annagramatic_primes; 
    for(auto i: primes) 
    {
        if(is_good(i)) annagramatic_primes.push_back(i);
    }

    
    ll n; 
    while(cin >> n)
    {
        if(n==0) break;
        if(n>=991) cout << 0 << endl; 
        else 
        {
            ll x = n ;
            ll t = 1 ; 
            while(x)
            {
                t*=10;
                x/=10;  
            }
            if(t<=n) t*=10; 
            bool ok = false;
            ll ans ;  
            for(auto i: annagramatic_primes)
            {
                if(i>n and i<=t)
                {
                    ans = i; 
                    ok = true; 
                    break;
                }
            }

            if(ok) cout << ans << endl; 
            else cout << 0 << endl; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}