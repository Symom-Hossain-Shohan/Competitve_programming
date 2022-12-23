#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n ;
    vector<ll> a(n), b(n); 
    for(auto &i: a) cin >> i ;
    for(auto &i: b) cin >> i; 

    ll mx = 0; 
    for(int i=0;i<n;i++)
    {
        mx = max(mx, a[i]-b[i]); 
    }

    for(int i=0;i<n;i++)
    {
        a[i] = max(0ll, a[i]-mx); 
    }
    if(a==b) cout << "YES\n"; 
    else cout << "NO\n"; 
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