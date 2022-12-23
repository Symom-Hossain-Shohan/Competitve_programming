#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    set<ll> s; 
    s.insert(v[0]); 
    ll ans = 0 ; 
    for(int i=1;i<n;i++)
    {
        ll x = *s.rbegin(); 
        if(x>v[i])
        {
            ans++;
            
            s.clear();
            if(i<n-1) s.insert(v[i+1]);
        }
        else s.insert(v[i]);
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}