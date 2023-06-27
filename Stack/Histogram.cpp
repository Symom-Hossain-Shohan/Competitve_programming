#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v ) cin >> i; 

    vector<ll> NSL(n); 

    stack<pair<ll,ll>> st; 
    for(int i=0;i<n;i++)
    {
        bool ok = true; 
        while(!st.empty())
        {
            ll cur = st.top().first; 
            if(cur>=v[i]) st.pop();
            else 
            {
                ok = false; 
                NSL[i] = st.top().second; 
                break;
            }
        }

        if(ok) NSL[i] = -1;
        st.push({v[i], i}); 
    }

    while(!st.empty()) st.pop();

    vector<ll> NSR(n);

    for(int i=n-1;i>=0; i--)
    {
        bool ok = true; 
        while(!st.empty())
        {
            ll cur = st.top().first; 
            if(cur>=v[i]) st.pop();
            else 
            {
                ok = false; 
                NSR[i] = st.top().second; 
                break;
            }
        }

        if(ok) NSR[i] = n; 
        st.push({v[i], i}); 
    }

    //reverse(NSR.begin(), NSR.end()); 
    // for(auto i: NSR) cout <<  i << ' '; 
    // cout << endl; 

    ll ans = 0; 
    for(int i = 0;i<n; i++)
    {
        ans = max(ans, (NSR[i]-NSL[i]-1)*v[i]); 
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
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}