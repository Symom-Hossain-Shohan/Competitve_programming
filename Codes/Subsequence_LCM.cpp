#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx = 1e5 + 5, mod = 1e9+7; 
map<ll,ll> cnt, freq; 

vector<ll> power(mx), fact(mx); 
ll ncr(ll n, ll r)
{
    ll res = 
}
void solve()
{
    ll n; 
    cin >> n; 
    cnt.clear(), freq.clear(); 
    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
    }
    ll ans = 0 ; 
    for(auto i: freq)
    {
        ll f = i.second ; 
        ll ans = (ans + power[f] - (f+1)+mod)%mod; 

        for(int j = 1; j*j<=i.first; j++)
        {
            if(i.first%j==0)
            {
                cnt[j] += f; 
                if(j>1) 
                {
                    ans = (ans - ncr(f, j) +mod)%mod; 
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
    power[0] = 1; 
    for(int i=1;i<=1e5;i++)
    {
        power[i] = (power[i-1]*2) % mod; 
    }
    fact[0] = 1; 
    for(int i = 1;i<=1e5;i++)
    {
        fact[i] = (i*fact[i-1]) % mod; 
    }
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}