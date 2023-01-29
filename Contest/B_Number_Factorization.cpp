#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mx = 32000; 

vector<bool> isprime(mx+1, true); 
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=mx;i+=2)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=mx;j+=2*i) isprime[j] = false; 
        } 
    }

    for(int i=3;i<=mx;i+=2) if(isprime[i]) primes.push_back(i);
}


void solve()
{
    ll n;
    cin >> n; 
    //factorize n
    vector<pair<ll,ll>> vp; 
    for(int i = 0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ll cnt = 0; 
            while(n%primes[i]==0)
            {
                cnt++; 
                n/=primes[i];
            }

            vp.push_back({cnt, primes[i]}); 
        }
    }

    if(n!=1) vp.push_back({1, n});

    sort(vp.begin(), vp.end()); 
    reverse(vp.begin(), vp.end()); 

    vector<ll> mul(vp.size());
    ll p = 0; 
    
    mul[0] = vp[0].second; 
    for(int i=1;i<vp.size();i++) mul[i] = mul[i-1]*vp[i].second; 
    ll ans = 0; 
    //for(auto i: vp) cout << i.first << ' ' << i.second <<endl; 
    for(int i=vp.size()-1;i>=0;i--)
    {
        //cout << mul[i] << ' ';
        ans += mul[i]*(vp[i].first-p); 
        p+= (vp[i].first-p); 
    }
    //cout << endl; 
    cout << ans << endl; 

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