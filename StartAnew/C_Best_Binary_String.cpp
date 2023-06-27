#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]=='?')
        {
            if(i==0) s[i] = '0';
            else s[i] = s[i-1];
        }
    }

    cout << s << endl; 
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