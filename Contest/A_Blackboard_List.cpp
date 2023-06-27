#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    map<ll,ll> mp; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 

    sort(v.begin(), v.end()); 
    if(v[0]<0) cout << v[0] << endl; 
    else cout << v.back() << endl; 

    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}