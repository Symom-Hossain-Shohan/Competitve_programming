#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; 
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 

    vector<int> f(n); 
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1; j<n;j ++) 
        {
            if(v[i]>v[j]) f[i]++; 
        }
    }

    ll ans = 0; 
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(v[j]>v[i]) f[j]--; 
        }
        vector<int> tm ; 
        tm = f; 
        for(int j = 1;j<=i;j++) tm[j] += tm[j-1]; 
        
        for(int j = 0;j<i;j++)
        {
            if(v[j]<v[i]) ans += tm[i-1] - tm[j]; 
        }
    } 
    cout << ans  << endl;
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