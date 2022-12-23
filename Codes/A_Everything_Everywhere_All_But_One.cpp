#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n) ; 
    ll sum = 0 ; 
    for(auto &i: v) 
    {
        cin >> i; 
        sum += i; 
    }
    bool ok = false; 
    for(int i=0;i<n;i++)
    {
        if(v[i]*(n-1)==sum-v[i])
        {
            ok = true;
            break;
        }
    }
    if(ok ) cout << "YES\n"; 
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