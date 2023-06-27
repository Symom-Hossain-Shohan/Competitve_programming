#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    for(int i=0;i<n ;i++) if(v[i]==1) v[i]++; 
    for(int i = 1;i<n; i++)
    {
        if(v[i]%v[i-1]==0) v[i]++; 
    }   
    for(auto i: v) cout << i << ' '; 
    cout << endl; 


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}