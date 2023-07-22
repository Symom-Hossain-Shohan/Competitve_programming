#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    vector<ll> dif; 
    for(int i = 0; i<n-1; i++) dif.push_back(abs(v[i]-v[i+1])); 

    n = dif.size();
    ll sum = 0;
    sort(dif.begin(), dif.end()); 
    for(int i=0;i<n-(k-1); i++) sum += dif[i];

    cout << sum << endl; 
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