#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    map<char, ll> mp; 
    for(int i=0;i<n;i++)
    {
        cin >> s; 
        mp[s[0]]++; 
    }

    //march
    ll ans = 0; 
    vector<char> v = {'M', 'A', 'R', 'C', 'H'}; 
    for(int i = 0;i<3;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            for(int k = j+1;k<5;k++)
            {
                ans += mp[v[i]]*mp[v[j]]*mp[v[k]]; 
            }
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