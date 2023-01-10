#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s ; 
    cin >> s; 
    bool ok = false; 
    ll x = -1; 
    for(int i=0;i+1<n;i++)
    {
        if(s[i]=='R' and s[i+1]=='L') 
        {
            ok = true; 
            break;
        }
        else if( s[i]=='L' and s[i+1]=='R')
        {
            x = i+1; 
            break;
        }
    }
    if(s[0]=='R' and s[n-1]=='L') ok = true; 
    if(ok) cout << 0 << endl; 
    else cout << x << endl; 
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