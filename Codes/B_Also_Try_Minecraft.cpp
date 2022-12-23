#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> v(n), left, right; 
    for(auto &i: v) cin >>  i; 

    left.push_back(0); 
    for(int i=1;i<n;i++)
    {
        if(v[i]<v[i-1]) left.push_back(v[i-1]-v[i]); 
        else left.push_back(0); 
    }
    right.resize(n); 
    right[n-1]= 0; 
    for(int i=n-2;i>=0;i--)
    {
        if(v[i+1]>v[i]) right[i]= v[i+1]-v[i]; 
        //else right.push_back(0); 
    }
    for(int i=1;i<n;i++) left[i] += left[i-1]; 

    for(int i=n-2;i>=0;i--) right[i] += right[i+1]; 

    while(m--)
    {
        ll l, r; 
        cin >> l >> r; 
        l--, r--; 
        if(l<=r) cout<< left[r] - left[l] << endl; 
        else cout << right[r] - right[l] << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}