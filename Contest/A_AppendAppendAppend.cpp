#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

void solve()
{
    string a, b; 
    cin >> a >> b; 
    map<char, vector<ll>> mp; 
    for(int i=0;i<(int)a.size();i++) mp[a[i]].push_back(i); 

    ll ans = 1, ix = mp[b[0]][0]; 

    for(int i=1;i<(int)b.size(); i++)
    {
        if(mp[b[i]].back()<=ix)
        {
            ans++; 
            ix = mp[b[i]][0]; 
        }
        else 
        {
            ll up = upper_bound(mp[b[i]].begin(), mp[b[i]].end(), ix) - mp[b[i]].begin(); 
            ix = mp[b[i]][up]; 
        }
    }

    cout << ans <<endl;
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