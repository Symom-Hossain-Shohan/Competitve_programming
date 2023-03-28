#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v;  
    for(int i=0;i<n;i++)
    {
        vector<ll> tmp; 
        ll sz; 
        cin >> sz; 
        for(int i=0;i<sz;i++)
        {
            ll x ; 
            cin >> x; 
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }

    map<ll,ll> mp;
    vector<ll> ans ; 
      
    for(int i=n-1;i>=0;i--)
    {
        bool ok = true;
        for(auto j: v[i])
        {
            if(mp[j]==0 and ok ==true)
            {
                ans.push_back(j);
                //cout << j << endl; 
                mp[j]++; 
                ok = false; 
                //break;
            }
            else mp[j]++; 
        }
        if(ok==true)
        {
            cout << -1 << endl; 
            return; 
        }
    }
    for(int i=n-1;i>=0;i--) cout << ans[i] << ' '; 
    cout << endl; 
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