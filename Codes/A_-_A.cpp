#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    ll ans = 0; 
    cin >> n; 
    vector<pair<ll, ll>> v(n);
    for(auto &i: v) cin >> i.first >> i.second ; 
    ll cnt = 0; 
    for(int i = 0; i < n ; i++)
    {
        if(v[i].first == v[i].second) cnt++; 
        else {
            ans = max(ans, cnt); 
            cnt = 0; 
        }
    }
    ans = max(ans, cnt); 
    if(ans >= 3) cout << "Yes\n"; 
    else cout << "No\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}