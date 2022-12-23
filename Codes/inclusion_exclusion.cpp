//You will be given an integer n. Determine how many numbers are there between 1 to n inclusive
//that the number is divisible by any of the prime number between 1 to 20

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19}; 
    ll ans = 0; 
    for(ll i=1;i<(1<<8); i++)
    {
    	ll d = 1ll, setBits = __builtin_popcountll(i); 
    	for(ll j = 0; j< 8; j++)
    	{
    		if(i & (1<<j))
    		{
    			d = d* primes[j]; 
    		}
    	}
    	if(setBits&1)
    	{
    		ans += n/d;
    		
    	}
    	else 
    	{
    		ans -= n/d; 
    		
    	}
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}