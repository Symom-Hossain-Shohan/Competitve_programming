#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

void solve()
{
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}; 
    ll n; 
    cin >> n; 
    ll x = 1ll; 
    ll ix = 0ll; 
    for(ll i=0;i<(ll)primes.size(); i++)
    {
        if(x*primes[i]<=n) x *= primes[i], ix = i; 
    }
    // while(x*3<=n) x*=3; 

    ll sum = 0ll; 
    for(ll mask = 1;mask<(1<<(ix+1)); mask++)
    {
        ll mul = 1; 
        if(__builtin_popcountll(mask) % 2 == 1)
        {
            for(ll j=0;j<=ix; j++)
            {
                if(mask & (1<<j))
                {
                    mul *= primes[j]; 
                }
            }
            if(mul==1) continue;
            
        

            sum += x/mul; 
        }
        else 
        {
            for(ll j=0;j<=ix; j++)
            {
                if(mask & (1<<j))
                {
                    mul *= primes[j]; 
                }
            }
            if(mul==1) continue;
            
            sum -= x/mul; 
        }
    }
    // cout << sum << endl; 
    // cout << x << ' ' << endl; 

    ll gcd = __gcd(x, sum); 
    cout << sum/gcd << "/" << x/gcd << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}