#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    map<ll,ll> mp; 
    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        mp[x] = i+1; 
    }
    if(n==1)
    {
        cout << 0 << endl; 
        return; 
    }
    else if(n%2==0)
    {
        ll l = mp[n/2], r = mp[n/2+1], ans=0; 
        if(l>r) ans++, l = -1, r = n+1; 
        for(int i = n/2-1, j=n/2+2; i>0;i--,j++)
        {
            if(mp[i]<l and mp[j]>r) l = mp[i], r = mp[j]; 
            else ans++, l = -1, r = n+1; 
            //cout << i << ' ' << j << endl; 
        }
        cout << ans << endl; 
    }
    else 
    {
        ll l = mp[n/2] , r = mp[n/2+2], ans = 0;  
        if(l>r) l = -1, r = n+1, ans++; 
        else if(mp[n/2+1]<l or mp[n/2+1]>r) l = -1, r = n+1, ans++; 
        for(int i=n/2-1, j=n/2+3;i>0;i--, j++)
        {
            if(mp[i]<l and mp[j]>r) l = mp[i], r = mp[j];
            else l = -1, r = n+1, ans++;
            //cout << i << ' ' << j << endl;  
        }
        cout << ans << endl; 
    }
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