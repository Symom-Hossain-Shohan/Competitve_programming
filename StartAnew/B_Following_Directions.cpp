#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    cin >> s; 

    ll x = 0, y = 0; 
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') y+=1; 
        else if(s[i]=='D') y -= 1;
        else if(s[i]=='L') x-=1; 
        else x += 1; 
        if(x==1 and y==1) 
        {
            cout << "YES\n";
            return; 
        } 
    }

    cout << "NO\n";
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