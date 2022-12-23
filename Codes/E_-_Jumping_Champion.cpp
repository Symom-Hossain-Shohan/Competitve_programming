#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx =  1000005; 

vector<bool> is_prime(mx, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i = 3;i*i<=1000000;i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i; j<=1000000;j+=2*i)
            {
                is_prime[j] = false; 
            }
        }
    }
    for(int i = 3;i<=1000000;i+=2) if(is_prime[i]) primes.push_back(i);
}

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    map<ll,ll> mp; 

    for(int i = 0;i<(int)primes.size();i++)
    {
        if(primes[i]>=n)
        {
            for(int j= i+1;primes[j]<=k and j<(int)primes.size();j++)
            {
                mp[primes[j]-primes[j-1]]++; 
            }
            break;
        }
    }
    if(mp.empty()) cout << "No jumping champion\n";
    else 
    {
        ll cnt = 0; 
        for(auto i: mp) 
        {
            cnt = max(cnt, i.second);
        }
        ll ans = 0; 
        for(auto i: mp) if(i.second==cnt) ans++; 
        if(ans!=1) cout << "No jumping champion\n";
        else 
        {
            for(auto i: mp)
            {
                if(i.second==cnt)
                {
                    cout << "The jumping champion is " << i.first << endl; 
                    break;
                }
            }
        }
    }
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