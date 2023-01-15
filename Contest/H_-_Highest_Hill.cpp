#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v;
    ll x; 
    cin >> x; 
    v.push_back(x);
    for(int i = 1;i<n;i++)
    {
        cin >>x; 
        if(v.back()!=x) v.push_back(x);
    } 
    n = v.size();
    vector<ll> index; 
    for(int i=1;i<n-1;i++) 
    {
        if(v[i]>=v[i-1] and v[i]>=v[i+1]) index.push_back(i); 
    }
    ll ans = 0; 
    for(auto i: index)
    {
        int j = i-1; 
        while(v[j-1]<=v[j] and j>0) j--; 
        int k = i+1; 
        while(v[k+1]<=v[k] and k<n-1) k++; 
        //cout << i << ' ' << j << ' ' << ' ' << k <<endl; 
        ans =max(ans, min(v[i]-v[j], v[i]-v[k])); 
    }
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