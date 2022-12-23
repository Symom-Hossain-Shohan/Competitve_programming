#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n; 
    vector<ll> a(n), b(n); 
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    vector<ll> ans; 
    ans.push_back(b[0]-a[0]);
    ll x = b[0]; 
    for(int i=1;i<n;i++)
    {
        if(a[i]<x)
        {
            ans.push_back(b[i]-x); 
        }
        else ans.push_back(b[i]-a[i]); 
        x = b[i]; 
    } 

    for(auto i: ans) cout << i << ' '; 
    cout << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}