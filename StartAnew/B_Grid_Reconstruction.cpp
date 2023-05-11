#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> a, b; 
    ll x = 2*n, y = 1; 
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            a.push_back(x); 
            x--; 
            b.push_back(x);
            x--; 
        }
        else 
        {
            b.push_back(y); 
            y++; 
            a.push_back(y); 
            y++; 
        }
    }
    for(auto i: a) cout << i << ' ';
    reverse(b.begin(), b.end()); 
    cout << endl; 
    for(auto i: b) cout<< i << ' '; 
    cout << endl; 
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