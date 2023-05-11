#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    for(int i=1;i<n-1; i++)
    {
        if(v[i-1]>v[i])
        {
            ll dif = v[i-1]-v[i]; 
            v[i] += dif; 
            v[i+1] += dif; 
        }
    }
    for(int i=n-2;i>0; i--)
    {
        if(v[i+1]<v[i])
        {
            ll dif = v[i]-v[i+1];
            v[i] -= dif; 
            v[i-1] -= dif; 
        }
    }

    if(is_sorted(v.begin(), v.end()) and v[0]<=v[n-1
    ]) cout << "YES\n"; 
    else cout << "NO\n"; 
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