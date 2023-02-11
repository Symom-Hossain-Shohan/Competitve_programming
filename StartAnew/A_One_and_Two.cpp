#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);

    for(auto &i: v) cin >> i; 

    vector<ll> l(n), r(n);
    l[0] = (v[0]==2);
    for(int i=1;i<n;i++)
    {
        l[i] =l[i-1] + (v[i]==2);
    }

    r[n-1] = (v[n-1]==2);
    for(int i=n-2;i>=0;i--)
    {
        r[i] = r[i+1] + (v[i]==2);
    }

    for(int i=0;i<n-1;i++)
    {
        if(l[i]==r[i+1]) {
            cout << i+1 << endl; 
            return; 
        }
    }

    cout << -1 << endl; 
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