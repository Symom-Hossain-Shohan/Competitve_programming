#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n) ; 
    ll sum = 0 ;
    for(auto &i: v) cin >> i, sum += i; 
    ll mx = *max_element(v.begin(), v.end()); 
    sum -= mx ;
    if(mx ==0 ) 
    {
        cout << 0 << endl; 
        return;
    }
    if(mx>sum) cout << mx - sum << endl; 
    else cout << 1 << endl; 
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