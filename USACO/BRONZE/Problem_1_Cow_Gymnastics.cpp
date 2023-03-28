#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll k, n; 
    cin >> k >> n; 
    ll ans = 0; 
    ll mtx[k][n]; 
    for(int i= 0;i<k;i++)
    {
        for(int j=0;j<n;j++) cin >> mtx[i][j]; 
    }
    for(int i=0;i<n;i++)
    {
        ll x = mtx[0][i];
        bool ok = true; 
        map<ll,ll> mp;  
        for(int j=0;j<k ;j++)
        {
            for(int k=0;k<n and ok;k++)
            {
                if(mtx[j][k]==x)
                {
                    for(int l=k+1;l<n;l++) mp[mtx[j][l]]++; 
                    break;
                }
            }
        }
        for(auto j: mp) if(j.second==k) ans++; 
        
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}