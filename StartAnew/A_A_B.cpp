#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s, a, b; 
    cin >> s; 
    bool ok = false; 
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='+') 
        {
            ok = true; 
            continue;
        }
        if(ok) a.push_back(s[i]);
        else b.push_back(s[i]);
    }

    cout << stoll(a) + stoll(b) << endl; 
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