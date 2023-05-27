#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<pair<ll,ll>, ll>> vp(n);
    for(int i=0;i<n;i++)
    {
        cin >> vp[i].first.first >> vp[i].first.second;
        if(vp[i].first.first>vp[i].first.second) swap(vp[i].first.first, vp[i].first.second);

        vp[i].second = i; 
    }

    sort(vp.begin(), vp.end()); 

    vector<ll> ans(n, -1);
    set<pair<ll,ll>> st, tmp; 
    // cout << endl; 
    // for(auto i: vp) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl; 
    // cout << endl; 
    tmp.insert({vp[0].first.second, vp[0].second});
    for(int i=1;i<n;i++)
    {
        
        if(vp[i].first.first==vp[i-1].first.first)
        {
            tmp.insert({vp[i-1].first.second, vp[i-1].second}); 
        }
        else 
        {
            for(auto j: tmp) st.insert(j);
            tmp.clear();
            tmp.insert({vp[i].first.second, vp[i].second}); 
        }
        if(!st.empty())
        {
            // cout << i << endl; 
            // for(auto j: st) cout << j.first << ' ';
            // cout << endl; 
            
            auto it = st.begin();
            if((*it).first<vp[i].first.second) 
            {
                ans[vp[i].second] = (*it).second+1; 
            }
        }
    } 
    
    for(auto i: ans) cout << i << ' ';
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