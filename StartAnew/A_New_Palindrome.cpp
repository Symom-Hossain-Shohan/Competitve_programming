#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    ll n = s.size();
    map<char, ll> mp; 
    for(auto i: s) mp[i]++; 
    ll cnt = 0; 
    if(n%2) mp[s[n/2]]--; 
    for(auto i:mp) if(i.second%2==0 and i.second>0) cnt++; 
    if(cnt>1) cout << "YES\n";
    else cout << "NO\n"; 
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