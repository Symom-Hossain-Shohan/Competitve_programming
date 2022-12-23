#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; 
    cin >> n >> k; 
    string s; 
    cin >> s ; 
    vector<ll> w(n+1); 
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W') w[i+1]++; 
    }
    for(int i=1;i<=n;i++) w[i]+=w[i-1]; 
    ll ans = 1e18; 

    for(int i=1;i<=n-k+1;i++)
    {
        ans = min(ans, w[i+k-1]-w[i-1]);  
    }
    cout << ans << endl; 
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