#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll k, n; 
    cin >> n >> k; 
    vector<ll> v; 
    ll x= 1; 
    v.push_back(0);
    v.push_back(1); 
    for(int i=2;i<=40;i++) 
    {
        v.push_back(v.back()+x); 
        x++; 
        //cout << x <<' ';
    } 
    ll ix = -1; 
    for(int i=0, j=n;j>=1;j--, i++)
    {
        if(k-v[j]>=i) 
        {
            ix = j; 
            break;
        }
    } 
    vector<ll> ans; 
    for(int i=1;i<=ix and n;i++, n--) ans.push_back(v[i]); 
    while(n--)  ans.push_back(ans.back()+1); 
    for(auto i: ans) cout << i << ' '; 
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