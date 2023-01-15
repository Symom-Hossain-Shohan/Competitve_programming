#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    ll ans = max(count(s.begin(), s.end(), 'a'), count(s.begin(), s.end(), 'b')); 
    //cout << ans << endl; 
    int n = s.size();
    vector<ll> a(n, 0), b(n,0);
    for(int i=0;i<n;i++) 
    {
        if(s[i]=='a') 
        {
            a[i] = 1; 
        }
        else 
        {
            b[i] = 1; 
        }
    }

    for(int i=1;i<n;i++) a[i] += a[i-1], b[i] += b[i-1];
    
    //ab
    for(int i = 1;i<n;i++)
    {
        ll x= a[i-1] + (b[n-1]-b[i-1]); 
        ans = max(x, ans); 
    }
    
    //ba
    for(int i=1;i<n;i++)
    {
        ll x = b[i-1] + (a[n-1]-a[i-1]); 
        ans = max(x, ans);
    }

    for(int i = 1;i<n-1;i++)
    {
        for(int j = i;j<n-1;j++)
        {
            ll x = a[i-1] + (a[n-1]-a[j]) + (b[j]-b[i-1]); 
            ans = max(ans, x);
        }
    }
    

    cout << ans << endl;    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}