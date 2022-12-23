#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> s(n-1), x(k); 
    for(auto &i: s) cin >> i; 
    for(auto &i: x) cin >> i; 
    
    vector<ll> b; 
    b.push_back(0); 
    for(int i= 0;i<n-1;i++)
    {
        b.push_back(s[i]-b.back()); 
    }
    
    map<ll,ll> mp ;
    for(int i=0;i<n;i++)
    {
        for(int j = 0 ;j<k;j++)
        {
            ll  t = x[j] - b[i]; 
            if(i%2==0) t*= -1; 
            mp[t]++; 
        }
    }

    ll ans = 0; 
    for(auto i: mp) ans = max(ans, i.second) ; 
    cout << ans << endl; 
    
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