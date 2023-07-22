#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<bool> isPrime(2e5+1, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=2e5; i+=2)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j<=2e5; j+= 2*i) isPrime[j] = false; 
        }
    }
    for(int i=3;i<=2e5; i+=2) if(isPrime[i]) primes.push_back(i); 
}


void solve()
{
    ll n; 
    cin >> n; 

    vector<ll> pm, nm; 
    for(int i=1;i<=n; i++)
    {
        if(binary_search(primes.begin(), primes.end(), i)) pm.push_back(i); 
        else nm.push_back(i);
    }

    vector<ll> a, b; 
    for(int i=pm.size()-1, k=0; i>=0; i--, k++)
    {
        if(k%2==0) a.push_back(pm[i]); 
        else b.push_back(pm[i]); 
    }
    
    ll x = nm.size();
    

    vector<ll> ans; 
    for(auto i: a) ans.push_back(i);
    for(auto i: nm) ans.push_back(i); 
    for(auto i: b) ans.push_back(i); 
    ll as = 0, ix = (int)a.size();
    for(int i=a.size(); i<((int)a.size()+(int)nm.size()); i++)
    {
       ll x = (i+1)*((int)a.size() + (int)nm.size()-i+1) + i; 
       if(x>as)
       {
            as = x; 
            ix = i; 
       }
    }

    for(int i=(int)a.size(); i<=ix-1; i++)
    {
        swap(ans[i], ans[i+1]); 
    }

    for(auto i: ans) cout << i << ' '; 
    cout << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;

    sieve();

    
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}