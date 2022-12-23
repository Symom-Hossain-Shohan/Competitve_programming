#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    map<ll,ll> mp; 
    for(int i = 0;i<n;i++)
    {
        cin >> v[i]; 
        v[i]%=10; 
        mp[v[i]]++; 
    }

    vector<ll> ans; 
    for(auto i:mp)
    {
        ll x = min(3ll, i.second); 
        while(x--) ans.push_back(i.first); 
    }

    for(int i=0;i<(int)ans.size(); i++)
    {
        for(int j = i+1;j<(int)ans.size();j++)
        {
            for(int k=j+1;k<(int)ans.size();k++)
            {
                if((ans[i]+ans[j]+ans[k])%10==3) 
                {
                    cout << "YES\n"; 
                    return; 
                }
            }
        }
    }
    cout << "NO\n"; 
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