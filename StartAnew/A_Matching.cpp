#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll ans = 1; 
    string s ; 
    cin >> s; 
    if(s[0]=='0')
    {
        cout << 0 << endl; 
    }
    else 
    {
        if(s[0]=='?') ans = 9; 
        for(int i=1;i<(int)s.length(); i++)
        {
            if(s[i]=='?') ans *= 10; 
        }
        cout << ans << endl; 
    }
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