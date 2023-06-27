#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    string s; 
    map<string, ll> mp; 
    for(int i=0;i<n;i++)
    {
        cin >> s; 
        mp[s]++;
    }


    ll res = 0; 

    if(mp["A"])
    {
        res = max(res, mp["A"] + mp["AB"]); 
    }

    if(mp["B"]) res = max(res, mp["B"] + mp["AB"]); 

    if(mp["AB"]) res = max(res, mp["AB"]); 

    if(mp["O"]) 
    {
        res = mp["O"] + res; 
    }

    cout << res << endl; 
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