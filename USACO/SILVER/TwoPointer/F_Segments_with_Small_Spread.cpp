#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    ll mx = 0, mn = 0, l = 0, r = 0, ans = 0; 
    multiset<ll> st; 
    map<ll,ll> mp; 
    for(; r<n; r++)
    {
        mp[v[r]] = r; 
        st.insert(v[r]);
        ll big , small; 
        auto it = st.begin();
        small = *it; 
        it = st.end();
        it--; 
        big = *it; 
        while(big-small>k)
        {
            st.erase(st.find(v[l])); 
            l++; 
            it = st.begin();
            small = *it; 
            it = st.end();
            it--; 
            big = *it;
        }

        ans += (r-l+1);  
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