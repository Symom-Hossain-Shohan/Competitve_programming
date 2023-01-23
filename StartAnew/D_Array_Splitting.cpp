#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 

    
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    vector<ll> vp ; 
    ll sum = v[n-1]; 
    vp.push_back(sum);
    for(int i = n-2;i>0;i--) 
    {
        sum += v[i];
        vp.push_back(sum);
    }
    sum += v[0];

    ll ans = sum; 
    sort(vp.rbegin(), vp.rend()); 

    for(int i=0;i<k-1;i++) ans += vp[i];

    cout << ans << endl; 


}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}