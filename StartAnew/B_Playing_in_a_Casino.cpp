#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{   
    ll n, m; 
    cin >> n >> m; 
    int ar[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >>ar[i][j];
    }

    ll ans = 0; 
    for(int j=0;j<m;j++)
    {
        vector<ll> tmp; 
        for(int i = 0;i<n;i++)
            tmp.push_back(ar[i][j]); 
        sort(tmp.begin(), tmp.end()); 
        for(int i=0;i<n;i++)
        {
            ans += i*tmp[i]; 
            ans -= (n-i-1) * tmp[i]; 
        }

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
        //cout << "kire";

        solve();
    }
    return 0;
}