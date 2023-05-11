#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    ll l = 0, r = 0; 
    vector<ll> v(m+1);
    map<ll,ll> mp; 
    for(int i=0;i<n; i++)
    {
        ll x; 
        cin >> x; 
        if(x==-1) l++; 
        else if(x==-2) r++; 
        else v[x] = 1, mp[x]++; 
    }
    for(int i=1;i<=m; i++) v[i] += v[i-1]; 
    ll ans = 1; 
    for(int i=1;i<=m; i++)
    {
        if(i==1)
        {
            if(mp[i])
            {
                ll x = v[m] - v[i];
                ll y = min(r, (m-i-x)); 
                ans = max(ans, x+y+1); 
            }
            else if(r>0)
            {
                ll x = v[m] - v[i];
                ll y = min(r-1, m-i-x); 
                ans = max(ans, x+y+1);
            }
        }
        else if(i==m)
        {
            if(mp[i])
            {
                ll x = v[i-1]; 
                ll y = min(l, m-1-x); 
                ans = max(ans, x+y+1); 
            }
            else if(l>0)
            {
                ll x = v[i-1]; 
                ll y = min(l-1, m-1-x); 
                ans = max(ans, x+y+1);
            }
        }
        else 
        {
            if(mp[i])
            {
                ll x = v[m] - v[i] ;
                x += min(r, m-i-x);  
                ll y = v[i-1]; 
                y += min(l, i-1-y); 
                ans = max(ans, x+y+1);
            }
        }
    }

    cout << ans << "\n";
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