#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    map<char, ll> m; 
    ll n; 
    cin >> n; 
    n = 2*n+1; 
    while(n--)
    {
        string s; 
        cin >> s; 
        for(auto i: s) m[i]++;
    }

    for(auto i: m)
    {
        if(i.second%2)
        {
            cout << i.first << endl; 
            break;
        }
    }
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