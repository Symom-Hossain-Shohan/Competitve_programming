#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i; 
    sort(a.begin(), a.end()); 

    for(int i = 1, j = n-1;i<n;i+=2, j--)
    {
        b[i] = a[j];
    }
    for(int i=0, j = 0;i<n;i+=2, j++)
    {
        b[i] = a[j];
    }
    for(auto i: b) cout << i << ' ';
    cout << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}