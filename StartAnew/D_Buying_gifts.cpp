#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    vector<pair<ll,ll>> vp(n);
    for(int i=0;i<n;i++)
    {
        cin >> vp[i].first >> vp[i].second;  
    }
    sort(vp.begin(), vp.end()); 
    

    vector<ll> vmx(n+1, INT_MIN); 
    for(int i=n-1;i>=0;i--) 
    {
        vmx[i] = max(vp[i].second, vmx[i+1]); 
    }
    set<ll> st; 

    ll ans = INT_MAX; 
    for(int i=0;i<n;i++)
    {
        ans = min(ans, abs(vp[i].first - vmx[i+1])); 
        auto it = st.lower_bound(vp[i].first); 

        if(it !=st.end() and *it> vmx[i+1]) ans =  min(ans, abs(vp[i].first - *it)); 
        if(it != st.begin() and *--it > vmx[i+1]) ans = min(ans, abs(vp[i].first - *it)); 

        st.insert(vp[i].second);         
    }
    cout << ans << endl; 
 
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