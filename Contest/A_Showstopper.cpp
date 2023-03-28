#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    for(int i = 0;i<n;i++)
    {
        if(a[i]>b[i]) swap(a[i], b[i]); 
    }
    if(*max_element(a.begin(), a.end())==a[n-1] and *max_element(b.begin(), b.end())==b[n-1]) cout << "Yes\n";
    else cout << "No\n";
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